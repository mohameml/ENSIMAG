#include <stdio.h>
#include <string.h>

#include "tab_chaine.h"
#include "matrice.h"
#include "bloc_8_fois_8.h"

typedef struct mcu_vect
{
    MCU_BLOC *data_vect_Y;
    MCU_BLOC *data_vcet_Cb;
    MCU_BLOC *data_vect_Cr;

} mcu_vect;

typedef strcut mcu_mat
{
    matrice data_Y;
    matrice data_Cb;
    matrice data_Cr;
}
mcu_mat;

typedef struct liste_chaine_mcu
{
    mcu_mat data;
    mcu_mat *suiv;
} liste_chaine_mcu;

tab_chaine order_appartion_comp(tab_chaine SOFO, tab_chaine SOS)
{
    // On recupere les identifients de composantes
    tab_chaine identifaint_Y = info_comp("Y", SOFO);
    tab_chaine identifaint_Cb = info_comp("Cb", SOFO);

    tab_chaine ordere_app = {0, NULL};

    if (strcmp(SOS.pointeur[3], identifaint_Y[0]) == 0)
    {
        ajouter_chaine(&ordere_app, "Y");

        if (strcmp(SOS.pointeur[5], identifaint_Cb[0] == 0))
        {
            ajouter_chaine(&ordere_app, "Cb");
            ajouter_chaine(&ordere_app, "Cr");

            liberer_haine(&identifaint_Y);
            liberer_chaine(&identifaint_Cb);

            return ordere_app;
        }
        else
        {
            ajouter_chaine(&ordere_app, "Cr");
            ajouter_chaine(&ordere_app, "Cb");

            liberer_haine(&identifaint_Y);
            liberer_chaine(&identifaint_Cb);

            return ordere_app;
        }
    }
    else if ((SOS.pointeur[3], identifaint_Cb[0]) == 0)
    {
        ajouter_chaine(&ordere_app, "Cb");

        if (strcmp(SOS.pointeur[5], identifaint_Y[0] == 0))
        {
            ajouter_chaine(&ordere_app, "Y");
            ajouter_chaine(&ordere_app, "Cr");

            liberer_haine(&identifaint_Y);
            liberer_chaine(&identifaint_Cb);

            return ordere_app;
        }
        else
        {
            ajouter_chaine(&ordere_app, "Cr");
            ajouter_chaine(&ordere_app, "Y");

            liberer_haine(&identifaint_Y);
            liberer_chaine(&identifaint_Cb);

            return ordere_app;
        }
    }
    else
    {
        ajouter_chaine(&ordere_app, "Cr");

        if (strcmp(SOS.pointeur[5], identifaint_Y[0] == 0))
        {
            ajouter_chaine(&ordere_app, "Y");
            ajouter_chaine(&ordere_app, "Cb");

            liberer_haine(&identifaint_Y);
            liberer_chaine(&identifaint_Cb);

            return ordere_app;
        }
        else
        {
            ajouter_chaine(&ordere_app, "Cb");
            ajouter_chaine(&ordere_app, "Y");

            liberer_haine(&identifaint_Y);
            liberer_chaine(&identifaint_Cb);

            return ordere_app;
        }
    }
}

int nb_appration_bloc_8_fois_8_dans_mcu(char *composante, tab_chaine SOFO)
{
    /*
    cette fonction prend a l'entree une compossnate et reetun le nb_bloc 8x8
    de ctte composannte daans une MCU
    */

    tab_chaine facteur_echan = info_comp(composante, SOFO);

    if (strcmp(facteur_echan[1], "21") == 0 || strcmp(facteur_echan[1], "12") == 0)
    {
        return 2;
    }
    else if (strcmp(facteur_echan[1], "22") == 0)
    {
        return 4;
    }
    else if (strcmp(facteur_echan[1], "11") == 0)
    {
        return 1;
    }
}

void decodage_Huffman_mcu(mcu_vect *mcu_flux, char *image_en_bin, tab_chaine tab_Hufffman_Y_DC, tab_chaine tab_Hufffman_Y_AC, tab_chaine tab_Hufffman_Cb_Cr_DC, tab_chaine tab_Hufffman_Cb_Cr_AC, tab_chaine SOS, tab_chaine SOFO, int *compteur, int *DC_precedent_Y, int *DC_prcedent_Cb, int *DC_precednt_Cr)
{
    // On recuoere l'ordere d'appartion de comp dans le flux
    tab_chaine ordere_app = order_appartion_comp(SOFO, SOS);

    // On recupere le nb d'apartion de bloc 8x8 dans une MCU :

    int nb_bloc_Y = nb_appration_bloc_8_fois_8_dans_mcu("Y", SOFO);
    int nb_bloc_Cb = nb_appration_bloc_8_fois_8_dans_mcu("Y", SOFO);
    int nb_bloc_Cr = nb_appration_bloc_8_fois_8_dans_mcu("Y", SOFO);

    //
    tab_chaine facteur_comp = info_comp("Y", SOFO);

    if (strcmp(ordere_app[0], "Y") == 0)
    {
        for (int i = 0; i < nb_bloc_Y; i++)
        {
            bloc_8_fois_8 bloc;
            decodage_imagee_Huffman(image_en_bin, tab_Huffman_Y_DC, tab_Huffman_Y_AC, compteur, DC_precedent_Y, bloc.data_vect_64);
            insere_mcu(mcu_flux->data_vect_Y, bloc);
        }

        if (strcmp(ordere_app[1], "Cb") == 0)
        {
            for (int i = 0; i < nb_bloc_Cb; i++)
            {
                bloc_8_fois_8 bloc;
                decodage_imagee_Huffman(image_en_bin, tab_Huffman_Cb_Cr_DC, tab_Huffman_Cb_Cr_AC, compteur, DC_precedent_Cb, bloc.data_vect_64);
                insere_mcu(mcu_flux->data_vect_Cb, bloc);
            }

            for (int i = 0; i < nb_bloc_Cr; i++)
            {
                bloc_8_fois_8 bloc;
                decodage_imagee_Huffman(image_en_bin, tab_Huffman_Cb_Cr_DC, tab_Huffman_Cb_Cr_AC, compteur, DC_precedent_Y, bloc.data_vect_64);
                insere_mcu(mcu_flux->data_vect_Cr, bloc);
            }
        }
        else
        {
            for (int i = 0; i < nb_bloc_Cr; i++)
            {
                bloc_8_fois_8 bloc;
                decodage_imagee_Huffman(image_en_bin, tab_Huffman_Cb_Cr_DC, tab_Huffman_Cb_Cr_AC, compteur, DC_precedent_Y, bloc.data_vect_64);
                insere_mcu(&(mcu_flux->data_vect_Cr), bloc);
            }

            for (int i = 0; i < nb_bloc_Cb; i++)
            {
                bloc_8_fois_8 bloc;
                decodage_imagee_Huffman(image_en_bin, tab_Huffman_Cb_Cr_DC, tab_Huffman_Cb_Cr_AC, compteur, DC_precedent_Cb, bloc.data_vect_64);
                insere_mcu(&(mcu_flux->data_vect_Cb), bloc);
            }
        }
    }
    else if (strcmp(ordere_app[0], "Cb") == 0)
    {
        for (int i = 0; i < nb_bloc_Cb; i++)
        {
            bloc_8_fois_8 bloc;
            decodage_imagee_Huffman(image_en_bin, tab_Huffman_Cb_Cr_DC, tab_Huffman_Cb_Cr_AC, compteur, DC_precedent_Cb, bloc.data_vect_64);
            insere_mcu(&(mcu_flux->data_vect_Cb), bloc);
        }

        if (strcmp(ordere_app[1], "Y") == 0)
        {
            for (int i = 0; i < nb_bloc_Y; i++)
            {
                bloc_8_fois_8 bloc;
                decodage_imagee_Huffman(image_en_bin, tab_Huffman_Y_DC, tab_Huffman_Y_AC, compteur, DC_precedent_Y, bloc.data_vect_64);
                insere_mcu(&(mcu_flux->data_vect_Y), bloc);
            }

            for (int i = 0; i < nb_bloc_Cr; i++)
            {
                bloc_8_fois_8 bloc;
                decodage_imagee_Huffman(image_en_bin, tab_Huffman_Cb_Cr_DC, tab_Huffman_Cb_Cr_AC, compteur, DC_precedent_Y, bloc.data_vect_64);
                insere_mcu(mcu_flux->data_vect_Cr, bloc);
            }
        }
        else
        {
            for (int i = 0; i < nb_bloc_Cr; i++)
            {
                bloc_8_fois_8 bloc;
                decodage_imagee_Huffman(image_en_bin, tab_Huffman_Cb_Cr_DC, tab_Huffman_Cb_Cr_AC, compteur, DC_precedent_Y, bloc.data_vect_64);
                insere_mcu(mcu_flux->data_vect_Cr, bloc);
            }

            for (int i = 0; i < nb_bloc_Y; i++)
            {
                bloc_8_fois_8 bloc;
                decodage_imagee_Huffman(image_en_bin, tab_Huffman_Y_DC, tab_Huffman_Y_AC, compteur, DC_precedent_Y, bloc.data_vect_64);
                insere_mcu(mcu_flux->data_vect_Y, bloc);
            }
        }
    }
    else
    {

        for (int i = 0; i < nb_bloc_Cr; i++)
        {
            bloc_8_fois_8 bloc;
            decodage_imagee_Huffman(image_en_bin, tab_Huffman_Cb_Cr_DC, tab_Huffman_Cb_Cr_AC, compteur, DC_precedent_Cb, bloc.data_vect_64);
            insere_mcu(mcu_flux->data_vect_Cr, bloc);
        }

        if (strcmp(ordere_app[1], "Y") == 0)
        {
            for (int i = 0; i < nb_bloc_Y; i++)
            {
                bloc_8_fois_8 bloc;
                decodage_imagee_Huffman(image_en_bin, tab_Huffman_Y_DC, tab_Huffman_Y_AC, compteur, DC_precedent_Y, bloc.data_vect_64);
                insere_mcu(mcu_flux->data_vect_Y, bloc);
            }

            for (int i = 0; i < nb_bloc_Cb; i++)
            {
                bloc_8_fois_8 bloc;
                decodage_imagee_Huffman(image_en_bin, tab_Huffman_Cb_Cr_DC, tab_Huffman_Cb_Cr_AC, compteur, DC_precedent_Y, bloc.data_vect_64);
                insere_mcu(mcu_flux->data_vect_Cb, bloc);
            }
        }
        else
        {
            for (int i = 0; i < nb_bloc_Cb; i++)
            {
                bloc_8_fois_8 bloc;
                decodage_imagee_Huffman(image_en_bin, tab_Huffman_Cb_Cr_DC, tab_Huffman_Cb_Cr_AC, compteur, DC_precedent_Y, bloc.data_vect_64);
                insere_mcu(mcu_flux->data_vect_Cb, bloc);
            }

            for (int i = 0; i < nb_bloc_Y; i++)
            {
                bloc_8_fois_8 bloc;
                decodage_imagee_Huffman(image_en_bin, tab_Huffman_Y_DC, tab_Huffman_Y_AC, compteur, DC_precedent_Y, bloc.data_vect_64);
                insere_mcu(mcu_flux->data_vect_Y, bloc);
            }
        }
    }
}

void traite_mcu(liste_chaine_mcu *image, mcu_vect *mcu_flux, mcu_mat *mcu, char *image_en_bin, tab_chaine tab_Hufffman_Y_DC, tab_chaine tab_Hufffman_Y_AC, tab_chaine tab_Hufffman_Cb_Cr_DC, tab_chaine tab_Hufffman_Cb_Cr_AC, tab_chaine SOS, tab_chaine SOFO, int *compteur, int *DC_precedent_Y, int *DC_prcedent_Cb, int *DC_precednt_Cr, tab_chaine tab_quant_Y, tab_chaine tab_quant_Cb_Cr)
{
    /* cette fonction traite une MCU de deocdage jusque YCbCr_vers_RGB  */

    /*--------------------- Decodage de MCU :   ---------------------------*/
    decodage_Huffman_mcu(mcu_flux, image_en_bin, tab_Hufffman_Y_DC, tab_Hufffman_Y_AC, tab_Hufffman_Cb_Cr_DC, tab_Hufffman_Cb_Cr_AC, SOS, SOFO, compteur, DC_precedent_Y, DC_prcedent_Cb, DC_precednt_Cr)

        /*----------------------- quantification -----------------------------*/

        // qunatification inverse de Y

        MCU_BLOC *data_Y = mcu_flux->data_vect_Y;

    while (data_Y != NULL)
    {
        quantification_inverse(data_Y->bloc.data_vect_64, tab_quant_Y);
        data_Y = data_Y->suiv;
    }

    // qunatification inverse de Cb

    MCU_BLOC *data_Cb = mcu_flux->data_vect_Cb;

    while (data_Cb != NULL)
    {
        quantification_inverse(data_Cb->bloc.data_vect_64, tab_quant_Cb_Cr);
        data_Cb = data_Cb->suiv;
    }

    // qunatification inverse de Cr

    MCU_BLOC *data_Cr = mcu_flux->data_vect_Cr;

    while (data_Cr != NULL)
    {
        quantification_inverse(data_Cr->bloc.data_vect_64, tab_quant_Cb_Cr);
        data_Cr = data_Cr->suiv;
    }

    /*---------------------------- zig_zag inverese -------------------------*/

    // zig_zag inverse de Y

    MCU_BLOC *data_Y = mcu_flux->data_vect_Y;

    while (data_Y != NULL)
    {
        zig_zag_inveres(data_Y->bloc.data_vect_64, data_Y->bloc.data_mat);
        data_Y = data_Y->suiv;
    }

    // zig_zag inverse de Cb

    MCU_BLOC *data_Cb = mcu_flux->data_vect_Cb;

    while (data_Cb != NULL)
    {
        zig_zag_inverse(data_Cb->bloc.data_vect_64, data_Cb->bloc.data_mat);
        data_Cb = data_Cb->suiv;
    }

    // zig_zag  inverse de Cr

    MCU_BLOC *data_Cr = mcu_flux->data_vect_Cr;

    while (data_Cr != NULL)
    {
        zig_zag_inverse(data_Cr->bloc.data_vect, data_Cr->bloc.data_mat);
        data_Cr = data_Cr->suiv;
    }

    /*---------------------- IDCT ------------------------------ */

    // IDCT de Y

    MCU_BLOC *data_Y = mcu_flux->data_vect_Y;

    while (data_Y != NULL)
    {
        int mat_sortie_idct[8][8];
        IDCT(data_Y->bloc.data_mat, mat_sortie_idct);
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                data_Y->bloc.data_mat[i][j] = mat_sortie_idct[i][j];
            }
        }
        data_Y = data_Y->suiv;
    }

    // IDCT de Cb

    MCU_BLOC *data_Cb = mcu_flux->data_vect_Cb;

    while (data_Cb != NULL)
    {
        int mat_sortie_idct[8][8];
        IDCT(data_Cb->bloc.data_mat, mat_sortie_idct);
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                data_Cb->bloc.data_mat[i][j] = mat_sortie_idct[i][j];
            }
        }
        data_Cb = data_Cb->suiv;
    }

    // IDCT de Cr

    MCU_BLOC *data_Cr = mcu_flux->data_vect_Cr;

    while (data_Cr != NULL)
    {
        int mat_sortie_idct[8][8];
        IDCT(data_Cr->bloc.data_mat, mat_sortie_idct);
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                data_Cr->bloc.data_mat[i][j] = mat_sortie_idct[i][j];
            }
        }
        data_Cr = data_Cr->suiv;
    }

    /*------------------ SUR échantillonnage ----------------------------*/

    data_vect_vers_data_mat(*mcu_flux, mcu, SOFO);
    sur_echantillonnage(mcu);

    /*------------- YCbCr vers RGB ----------------------------*/

    YCbCr_vers_RGB(mcu);

    /*---------------- Insere le mcu dans  liste chaine ------------*/

    insere_liste_chaine(image, mcu);
}

void data_vect_vers_data_mat(mcu_vect mcu_flux, mcu_mat *mcu, tab_chaine SOFO)
{
    /*---------- Y -----------------*/

    // data_vect_Y vers data_Y de mcu_mat
    tab_chaine info_comp_Y = info_comp("Y", SOFO);
    mcu->data_Y.pointeur = NULL;
    initialiser_matrice(&mcu->data_Y, atoi(info_comp_Y.pointeur[1][0]) * 8, atoi(info_comp_Y.pointeur[1][1]) * 8);
    liberer_chaine(&info_comp_Y);

    // On remplir la matrice de Y
    MCU_BLOC *data_Y = mcu_flux.data_vcet_Y;

    int compteur_ligne = mcu->data_Y.taille_ligne / 8;
    int compteur_colone = mcu->data_Y.taille_colone / 8;

    for (int parcour_ligne = 0; parcour_ligne < compteur_ligne; parcour_ligne++)
    {
        for (int parcour_colone = 0; parcour_colone < compteur_colone; parcour_colone++)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    ajouter_elme(&mcu->data_Y, data_Y->bloc.data_mat[i][j], parcour_ligne * 8 + i, parcour_colone * 8 + j);
                }
            }
            data_Y = data_Y->suiv;
        }
    }

    /*---------- Cb -----------------*/

    // data_vect_Cb vers data_Cb de mcu_mat

    tab_chaine info_comp_Cb = info_comp("Cb", SOFO);
    mcu->data_Cb.pointeur = NULL;
    initialiser_matrice(&mcu->data_Cb, atoi(info_comp_Cb.pointeur[1][0]) * 8, atoi(info_comp_Cb.pointeur[1][1]) * 8);
    liberer_chaine(&info_comp_Cb);

    // On remplir la matrice de Cb

    MCU_BLOC *data_Cb = mcu_flux.data_vcet_Cb;

    int compteur_ligne = mcu->data_Cb.taille_ligne / 8;
    int compteur_colone = mcu->data_Cr.taille_colone / 8;

    for (int parcour_ligne = 0; parcour_ligne < compteur_ligne; parcour_ligne++)
    {
        for (int parcour_colone = 0; parcour_colone < compteur_colone; parcour_colone++)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    ajouter_elme(&mcu->data_Cb, data_Cb->bloc.data_mat[i][j], parcour_ligne * 8 + i, parcour_colone * 8 + j);
                }
            }
            data_Cb = data_Cb->suiv;
        }
    }

    /*---------- Cr -----------------*/

    // data_vect_Cr vers data_Cr de mcu_mat
    tab_chaine info_comp_Cr = info_comp("Cr", SOFO);
    mcu->data_Cr.pointeur = NULL;
    initialiser_matrice(&mcu->data_Cr, atoi(info_comp_Cr.pointeur[1][0]) * 8, atoi(info_comp_Cr.pointeur[1][1]) * 8);
    liberer_chaine(&info_comp_Cr);

    // On remplir la matrice de Cr

    MCU_BLOC *data_Cr = mcu_flux.data_vcet_Cr;

    int compteur_ligne = mcu->data_Cr.taille_ligne / 8;
    int compteur_colone = mcu->data_Cr.taille_colone / 8;

    for (int parcour_ligne = 0; parcour_ligne < compteur_ligne; parcour_ligne++)
    {
        for (int parcour_colone = 0; parcour_colone < compteur_colone; parcour_colone++)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    ajouter_elme(&mcu->data_Cr, data_Cr->bloc.data_mat[i][j], parcour_ligne * 8 + i, parcour_colone * 8 + j);
                }
            }
            data_Cr = data_Cr->suiv;
        }
    }
}

void ecriture_ligne_ppm(char *nom_fichier, mcu_image image, int numero_ligne)
{
}

void ecrtiure_ppm(char *nom_fichier, mcu_image image, tab_chainne taille)
{
}