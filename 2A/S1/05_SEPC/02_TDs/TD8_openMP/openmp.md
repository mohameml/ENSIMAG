# +TITLE: Introduction à OpenMP
# +AUTHOR: Grégory Mounié
# +EMAIL: ENSIMAG 2A - APP
# +LANGUAGE: fr
# +SELECT_TAGS: export
# +EXCLUDE_TAGS: noexport solution
# +CREATOR: Emacs 25.1.1 (Org mode 9.0.3)

# +INCLUDE: "./entetes.org"

@@latex:\thispagestyle{fancy}@@

* OpenMP
  OpenMP est une extension de C, C++ et Fortran permettant de créer
  "facilement" des programmes parallèles multi-threadés. La syntaxe
  est beaucoup plus simple qu'une programmation à la main en Thread
  POSIX ou en C-11. Les opérateurs fournis sont également de beaucoup
  plus haut niveau.

  Néanmoins, le niveau d'expertise nécessaire pour écrire un programme
  s'exécutant le plus rapidement possible reste très élevé. Vous pouvez
  travailler en groupe à plusieurs si cela est possible.

  Ce TP a donc trois buts:
  1) vous faire écrire la version parallèle de deux petits problèmes
  2) vous faire mesurer les performances de votre implantation et la
     comparer à l'exécution séquentielle.
  3) Comprendre les points important dans votre implantation pour
     qu'elle aille le plus vite possible.

Les comparaisons de temps sont plus intéressantes lorsqu'elles sont
réalisées sur les machines physiques. Dans une VM, de nombreux
paramètres liés à la VM, sa technologie et sa configuration, peuvent
impacter fortement les mesures. Chaque groupe indiquera au tableau son temps
d'exécution. Celui ayant obtenu le meilleur temps doit aussi expliquer
comment.

** Préparation: la compilation
   En utilisant gcc ou clang, compiler un programme C minimaliste en
   ajoutant comme option de compilation =-fopenmp=.

#+begin_src C :tangle helloomp.c
  #include <stdio.h>
  #include <omp.h>

  int main(int argc, char **argv) {
      (void) argc;
      (void) argv;
      printf("hello avec %d thread\n", omp_get_num_threads()); // 1 seul thread lancé
  }
#+end_src

  L'exécution de ce programme devrait afficher *hello avec 1 thread*.

* Challenge 1: "Hello world !" à plusieurs
** Lancer plusieurs threads
   Pour donner des directives openmp au compilateur, le programmeur
   ajoute des =#pragma omp=.

   Ajoutez à votre programme un bloc précédé démarrant automatiquement
   plusieurs threads avec la directive =parallel=. Si vous avez une
   machine multi-cœur, vous devriez voir plusieurs /hello/.

   #+begin_src C :tangle hellopar.c
     #include <stdio.h>
     #include <omp.h>

     int main(int argc, char **argv) {
	 (void) argc;
	 (void) argv;

     #pragma omp parallel
	 {
	     printf("hello de %d/%d\n", omp_get_thread_num(),
		    omp_get_num_threads());

	 }
     }
   #+end_src

** Faire le travail par un seul thread
   Ajoutez un bloc précédé de la directive =single= pour ne faire
   réaliser le /hello/ que par un seul thread.

   #+begin_src C :tangle hellosingle.c
     #include <stdio.h>
     #include <omp.h>

     int main(int argc, char **argv) {
	 (void) argc;
	 (void) argv;

     #pragma omp parallel
	 {
     #pragma omp single
	     {
		 printf("hello de %d/%d\n", omp_get_thread_num(),
			omp_get_num_threads());
	     }
	 }
     }
   #+end_src

   Si vous lancez le programme plusieurs fois, il est possible que le
   numéro du thread varie. Pour que le travail soit toujours fait par
   le thread 0, il faut utiliser plutôt la directive =master=.

** Boucle parallèle
   Ajouter une boucle pour faire 25 /hello/ affichant en plus le
   numéro de l'itération avec la directive =for=. Attention, vous ne
   pouvez pas être dans une directive =single=.

   #+begin_src C :tangle hellofor.c
     #include <stdio.h>
     #include <omp.h>

     int main(int argc, char **argv) {
	 (void) argc;
	 (void) argv;

     #pragma omp parallel
	 {
     #pragma omp for
	     for(int i=0; i < 25; i++) {
		 printf("hello[%d] de %d/%d\n", i, omp_get_thread_num(),
			omp_get_num_threads());
	     }
	 }
     }
   #+end_src

** Changer l'ordonnancement de la boucle
   Ajoutez à la directive =for= l'option =schedule(dynamic)=,
   =schedule(static)= ou bien =schedule(guided)=

* Challenge 2: Fibonacci en parallèle avec des tâches
  En utilisant les tasks OpenMP, vous allez réaliser un programme parallèle
  calculant fibo(47).

** La version séquentielle
   Compilez une version séquentielle avec les options d'optimisations
   comme =-O3=. Ajustez la valeur pour calculer environ pendant 8
   secondes.
 
  #+begin_src C :tangle fibo_seq.c
    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>

    uint64_t fibo_seq(uint32_t n) {
	if (n < 2)
	    return n;

	return fibo_seq(n-1) + fibo_seq(n-2);
    }

    int main(int argc, char **argv) {
	(void) argc;
	(void) argv;
    
	printf("%lu\n", fibo_seq(47)); // ajustez pour durer 8s
	return EXIT_SUCCESS;
    }

  #+end_src

** Lancer plusieurs tâches
   Copiez la fonction =fibo_seq= en une fonction =fibo_par=.  Ajoutez
   un bloc =parallel= et un bloc =single= autour du calcul.  Vérifiez
   que vous obtenez un temps comparable au temps séquentiel.


*** solution                                                       :solution:
  #+begin_src C
    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>

    uint64_t fibo_seq(uint32_t n) {
	if (n < 2)
	    return n;

	return fibo_seq(n-1) + fibo_seq(n-2);
    }

    uint64_t fibo_par(uint32_t n) {
	if (n < 2)
	    return n;

	return fibo_par(n-1) + fibo_par(n-2);
    }

    int main(int argc, char **argv) {
	(void) argc;
	(void) argv;
    #pragma omp parallel
	{
    #pragma omp single
	    {
		printf("%lu\n", fibo_par(47)); // ajustez pour durer 8s
	    }
	}
	return EXIT_SUCCESS;
    }

  #+end_src

** Tâches
   Changez le calcul, pour celui de =fibo_par(7)= car il va devenir plus
   lourd pour l'instant.

   Nous allons utiliser la notion de tâche. Une tâche est créée par la
   directive =task=. La fin de toutes les tâches lancées par la tâche
   courante est obtenue avec la directive =taskwait=.

   Dans le =main=, lancez le calcul dans une tâche. Dans =fibo_par=,
   lancer les deux calculs dans une tâche. Pour cela il faudra
   sûrement ajoutez quelques variables temporaires.

   Attendez la fin des calculs avant de faire la somme des résultats.

   Compilez et exécutez votre code.
** Tâches et dépendances de données
   Pour bien comprendre les interactions avec les variables ajoutez
   l'option =default(none)= à vos créations de tâches. Et compiler de
   nouveau pour voir apparaître des messages d'erreurs.

   Il faut maintenant ajouter, *avant =default(none)=,* une option
   =shared(liste-de-variable)= pour indiquer que vos temporaires sont
   partagées entre la tâche créée et la tâche courante. De même
   =firstprivate(liste-de-variable)= crée automatiquement un
   temporaire pour =n= en copiant la valeur initiale lors de la
   création de la tâche.

*** Solution                                                       :solution:
  #+begin_src C :tangle fibo_tasksimple.c
    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>

    uint64_t fibo_seq(uint32_t n) {
	if (n < 2)
	    return n;

	return fibo_seq(n-1) + fibo_seq(n-2);
    }

    uint64_t fibo_par(uint32_t n) {
	if (n < 2)
	    return n;

	uint64_t r1;
	uint64_t r2;
    #pragma omp task shared(r1) firstprivate(n) default(none) 
	r1 = fibo_par(n-1);
    #pragma omp task shared(r2) firstprivate(n) default(none) 
	r2 = fibo_par(n-2);
    #pragma omp taskwait    
	return r1 + r2;
    }

    int main(int argc, char **argv) {
	(void) argc;
	(void) argv;
    #pragma omp parallel
	{
    #pragma omp single
	    {
		uint64_t res;

    #pragma omp task  shared(res) default(none)
		res = fibo_par(7);

    #pragma omp taskwait
		printf("%lu\n", res); // ajustez pour durer 8s
	    }
	}
	return EXIT_SUCCESS;
    }

  #+end_src

** Rayon de coupure
   La création d'une tâche est beaucoup plus coûteuse qu'une addition.
   Pour limiter ce surcoût, il faut de rebasculer vers l'algorithme
   séquentiel lorsqu'il y a assez de tâches.

   Ajoutez un paramètre =prof= à =fibo_par= qui sera initialisé à 6
   dans le =main= et décrémenté de 1 à chaque appel récursif de =fibo_par= .

   #+begin_src C
     uint64_t fibo_par(uint32_t n, int prof) {
	 if (prof <= 0)
	     return fibo_seq(n);
     ...
   #+end_src

   Vous devriez maintenant pouvoir recalculer =fibo_par(47)= et aller
   plus vite que le séquentiel. Cherchez la valeur initiale de la
   profondeur idéale pour =fibo_par(47)=.

*** Solution                                                       :solution:
  #+begin_src C :tangle fibo_taskoptim.c
    #include <stdint.h>
    #include <stdio.h>
    #include <stdlib.h>

    uint64_t fibo_seq(uint32_t n) {
	if (n < 2)
	    return n;

	return fibo_seq(n-1) + fibo_seq(n-2);
    }

    uint64_t fibo_par(uint32_t n, uint32_t prof) {
	 if (prof <= 0)
	     return fibo_seq(n);

	if (n < 2)
	    return n;

	uint64_t r1;
	uint64_t r2;
    #pragma omp task shared(r1) firstprivate(n,prof) default(none) 
	r1 = fibo_par(n-1, prof-1);
    #pragma omp task shared(r2) firstprivate(n,prof) default(none) 
	r2 = fibo_par(n-2, prof-1);
    #pragma omp taskwait    
	return r1 + r2;
    }

    int main(int argc, char **argv) {
	(void) argc;
	(void) argv;
    #pragma omp parallel
	{
    #pragma omp single
	    {
		uint64_t res;

    #pragma omp task lastprivate(res) default(none)
		res = fibo_par(47,4);

    #pragma omp taskwait
		printf("%lu\n", res); // ajustez pour durer 8s
	    }
	}
	return EXIT_SUCCESS;
    }

  #+end_src

** Tâches avec dépendances
   Ce denier exercice ne va pas améliorer les performances, mais il
   présente un point important dans les véritables applications: la
   gestion fine des dépendances de données.

   Il est possible de synchroniser plus finement les interactions
   entre les tâches en indiquant si pour une tâche, une variable est
   lue ou écrite. Ajoutez une tâche pour le calcul de la =somme()=.  Il est
   possible d'indiquer qu'elle attend le calcul d'une variable avec
   =depend(int:VARIABLE)=, résultat du calcul d'une tâche précédente
   utilisant l'option =depend(out:VARIABLE)=. Cela ne dispense pas de
   correctement déclarer les =shared(liste-de-variables)=.


*** Solution                                                       :solution:
    #+begin_src C :tangle fibo_taskdepend.c
      #include <stdint.h>
      #include <stdio.h>
      #include <stdlib.h>
      #include <stdbool.h>
      #include <omp.h>

      uint64_t fibo_seq(uint32_t n) {
	  if (n < 2)
	      return n;

	  return fibo_seq(n-1) + fibo_seq(n-2);
      }


      uint64_t somme(uint64_t r1, uint64_t r2) {
	  return r1 + r2;
      }

      uint64_t fibo_par(uint32_t n, int prof) {
	  if (prof <= 0)
	      return fibo_seq(n);

	  // printf("%d from %d\n", n, omp_get_thread_num());
	  if (n < 2)
	      return n;

	  uint64_t res1;
	  uint64_t res2;
	  uint64_t res;

      #pragma omp task depend(out:res1) firstprivate(n,prof) shared(res1) default(none) final((prof-1)==0) 
	  res1 = fibo_par(n-1, prof-1);

      #pragma omp task depend(out:res2) firstprivate(n,prof) shared(res2) default(none) final((prof-1)==0)
	  res2 = fibo_par(n-2, prof-1);

      #pragma omp task shared(res,res1,res2) depend(in:res1,res2) final(true) default(none)
	  res = somme(res1, res2);

      #pragma omp taskwait
	  return res;
      }


      int main(int argc, char **argv) {
	  (void) argc;
	  (void) argv;
	  uint64_t val;
      #pragma omp parallel
	  {
      #pragma omp single
	      {
      #pragma omp task shared(val)
		  val = fibo_par(47, 4);    
	      }
	  }
	  printf("%lu\n", val); // environ 8s sur mon laptop
	  return EXIT_SUCCESS;
      }

    #+end_src


*** Alternative: solution avec des variables pointeurs en sortie   :solution:
    #+begin_src C :tangle fibo_taskdependpointeur.c
      #include <stdint.h>
      #include <stdio.h>
      #include <stdlib.h>
      #include <omp.h>

      uint64_t fibo_seq(uint32_t n) {
	  if (n < 2)
	      return n;

	  return fibo_seq(n-1) + fibo_seq(n-2);
      }


      void somme(uint64_t *r1, uint64_t *r2, uint64_t *res) {
	  *res = *r1 + *r2;
	  free(r1);
	  free(r2);
      }

      void fibo_par(uint32_t n, uint64_t *res, int prof) {
	  if (prof <= 0) {
	      *res= fibo_seq(n);
	      return;
	  }

	  // printf("%d from %d\n", n, omp_get_thread_num());
	  if (n < 2) {
	      *res = n;
	      return;
	  }

	  uint64_t *res1= malloc(sizeof(uint64_t));
	  uint64_t *res2= malloc(sizeof(uint64_t));

      #pragma omp task depend(out:res1) 
	  fibo_par(n-1, res1, prof-1);

      #pragma omp task depend(out:res2)
	  fibo_par(n-2, res2, prof-1);

      #pragma omp task shared(res) depend(in:res1,res2)
	  somme(res1, res2, res);

      #pragma omp taskwait
      }


      int main(int argc, char **argv) {
	  (void) argc;
	  (void) argv;
	  uint64_t val;
      #pragma omp parallel
	  {
      #pragma omp single
	      {
      #pragma omp task shared(val)
		  fibo_par(47, &val, 4);

	      }
	  }
	  printf("%lu\n", val); // environ 8s sur mon laptop
	  return EXIT_SUCCESS;
      }

    #+end_src
* Challenge bonus: Mandelbrot en 4K
  En utilisant les opérateurs sur les boucles OpenMP, calculer
  l'ensemble de mandelbrot dans une résolution de 3 840 × 2 160.

  Pour rappel, pour chaque point complexe, on calcule le nombre
  d'itérations avant que la suite ne diverge.

  Le programme calcule ensuite la somme des valeurs entières obtenues
  pour tous les points et affiche cette somme.

* Pour vous aider:
  - Le cours parallélisme (SEPC, Semestre 1)
  - les sources des squelettes de départ sur github
    =git clone git@github.com:gmounie/ensimag-openmp.git=
  - le site OpenMP [[http://openmp.org]] (en particulier la Summary card
    ou Quick Reference Card)
