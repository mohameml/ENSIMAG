#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>
#include<omp.h>

#ifdef VersionNAIVE 
  #define METHODE "Version_Iterative"
  #define transpose(A,B,n,m) transposeV1(A,B,n,m)
  #define transpose(A,B,n,m) transposeV1(A,B,n,m)
#elif VersionBLOC
  #define METHODE "Version_par_Bloc_" 
  #define transpose(A,B,n,m) transposeV2(A,B,n,m)
#elif VersionRECURSIVE
  #define METHODE "Version_Recursive" 
  #define transpose(A,B,n,m) transposeV3(A,B,n,m)
#elif VersionRECURSIVE_PAR
  #define METHODE "Version_Rec_Parallel" 
  #define transpose(A,B,n,m) transposeV4(A,B,n,m)
#else 
  #define transpose(A,B,n,m) fprintf(stderr, "ERREUR: compiler avec -D[option] où option = [VersionNAIVE | VersionBLOC | VersionRECURSIVE ]\n") ; 
#endif

/// Version Naive
void transposeV1(double*A, double*B, int m, int n) {
   for(int i = 0 ; i < m ; i++) {
      for(int j = 0 ; j < n ; j++) {
          B[j*m+i] = A[i*n+j];
      }
   }
}

#define min(a,b) ( (a) < (b) ? (a) : (b) ) 

/// Version par bloc de taille K (avec K < taille cache / 2 )
static int K=20; /* Taille d'arret iteratif bidim = taille cache i (valeur par defaut) */
void transposeV2 ( double*A, double*B, int m, int n) { 
    for (int I=0; I < m; I += K)  
      for (int J=0; J < n;  J += K) { 
        // Transposition du bloc I, J
        int i_end = min( I+K, m ) ;
        int j_end = min( J+K, n ) ;
        for (int i=I; i < i_end; ++i) 
          for (int j=J; j < j_end; ++j) 
             B[j*m+i] = A[i*n+j];
      }
}

/// Version récursive jusqu'à un eseuil d'arrêt S
static int  S=20; /* Seuil d'arrêt récursif (valeur par defaut) */
// Sur les indices : un suffixe b correspond à begin, e à end.
void transposeRec( double* A, int mAb, int mAe, int nAb, int nAe, 
                   double* B, int m, int n) {
    int nblines = mAe - mAb; int   nbcols = nAe - nAb; 
    if (( nblines <= S ) && (nbcols <= S)) {  
      int iA, jA ;
      for ( iA=mAb; iA < mAe; ++iA )
        for ( jA=nAb; jA < nAe; ++jA )
             // B[jB*m+iB] = A[iA*n+jA];
             B[jA*m+iA] = A[iA*n+jA];
    }
    else if ( nblines > nbcols ) {
        int mid = nblines / 2 ; 
        transposeRec( A, mAb + mid, mAe, nAb, nAe, B, m, n); 
        transposeRec( A, mAb, mAb + mid, nAb, nAe, B, m, n);
    } 
    else {
        int mid = nbcols / 2 ; 
        transposeRec( A, mAb, mAe, nAb + mid, nAe, B, m, n);
        transposeRec( A, mAb, mAe, nAb, nAb + mid, B, m, n);
    }
}

void transposeV3 ( double*A, double*B, int m, int n) { 
    transposeRec(A, 0, m, 0, n, B, n, m) ; 
}

/// Version récursive jusqu'à un seuil d'arrêt parallele SPAR
static int  SPAR=400; /* Seuil d'arrêt récursif (valeur par defaut) */
// Sur les indices : un suffixe b correspond à begin, e à end.
void transposeRecPar( double* A, int mAb, int mAe, int nAb, int nAe, 
                   double* B, int m, int n ) {
    int nblines = mAe - mAb;  int  nbcols = nAe - nAb; 
    if (( nblines <= SPAR ) && (nbcols <= SPAR)) {  
      transposeRec( A, mAb, mAe, nAb, nAe, B, m, n) ; 
    }
    else if ( nblines > nbcols ) {
        int mid = nblines / 2 ; 
        #pragma omp task // untied  // pour parallèliser le calcul (la moitié, récursivement) 
        { transposeRecPar( A, mAb + mid, mAe, nAb, nAe, B, m, n ) ; }
        transposeRecPar( A, mAb, mAb + mid, nAb, nAe, B, m, n ) ; 
    } 
    else {
        int mid = nbcols / 2 ; 
        #pragma omp task // untied  // pour parallèliser le calcul (la moitié, récursivement) 
        { transposeRecPar( A, mAb, mAe, nAb + mid, nAe, B, m, n ) ; }
        transposeRecPar( A, mAb, mAe, nAb, nAb + mid, B, m, n ) ; 
    }
}

void transposeV4 ( double*A, double*B, int m, int n) { 
  if (m+n <= 2*S)
    transposeV1(A, B, m, n) ;
  else if ( m+n <= SPAR) 
    transposeRec(A, 0, m, 0, n, B, m, n) ;
  else { 
    #pragma omp parallel
    { // Debut section parallele sur tous les threads
      #pragma omp single nowait
      { // Un seul thread lance le calcul
        transposeRecPar(A, 0, m, 0, n, B, m, n) ;
      }
    }
  }
}


int main(int argc, char **argv) {

if (argc < 3) {
   fprintf( stderr, "%s: Usage: %s m n [S [SPAR]]\n where n, m, and s are 3 positive integers:"
                    "\n\t n = number of lines" 
                    "\n\t m = number of columns" 
                    "\n\t S = threshold (by default 20 for block iterative, 20 for recursive)\n",
                    "\n\t SPAR = threshold for parallelism \n",
		         argv[0], argv[0] ) ;
   return 1 ;
}

	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
if (argc > 3) K = S = atoi(argv[3]);
if (argc > 4) SPAR = atoi(argv[4]);

	double *A = malloc(sizeof(double)*m*n);
	// double *A = calloc(n*m, sizeof(double));
	if (A == NULL) {
		perror("failed");
	}

  #ifdef VERIF_TRANSPOSE
	/* Init A: for verification purpose  */
	{ long cptr = 0 ;
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j, ++cptr)
        A[i*n+j] = cptr ;
  }
  #endif // VERIF_TRANSPOSE

	double *B = malloc(sizeof(double)*m*n);
	// double *B = calloc(n*m, sizeof(double));


	//destroy cache
	double *C = malloc(sizeof(double)*10000000);
	for(int i = 0 ; i < 10000000 ; i++) {
		C[i] = 0;
	}
	for(int i = 0 ; i < 10000000 ; i++) {
		C[i] += 1;
	}


	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);
  transpose( A, B, m, n ) ; 
	gettimeofday(&end, NULL);
	// printf("%s\t %d\t %d \t %f\n", METHODE, n, m, (end.tv_sec - start.tv_sec)+(end.tv_usec - start.tv_usec)/(float)1000000);
	printf("\t %f", (end.tv_sec - start.tv_sec)+(end.tv_usec - start.tv_usec)/(float)1000000);

  #ifdef VERIF_TRANSPOSE
  /*  verification of B  */
  { 
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j) {
        if (B[ j*m + i ] != A[i*n+j] ) {
          printf("ERREUR DANS LA TRANSPOSITION : i=%d, j=%d A[i,j]=%g B[j,i]=%g \n", i, j, A[ i*n + j], B[ j*m + i ]); 
          return -1 ; 
        }
      }
  }
  #endif // VERIF_TRANSPOSE

	return 0 ;
}
