#! /bin/sh

# Lister tout les dossiers du repertoire courant
for n in *; do
    if [ -d "$n" ]; then
	echo "$n"
    fi
done

