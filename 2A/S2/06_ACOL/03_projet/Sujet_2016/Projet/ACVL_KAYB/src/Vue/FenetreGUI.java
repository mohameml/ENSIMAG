package Vue;
/**
 * \file FenetreGUI.java
 * \brief Implementation of the class FenetreGUI
 * \author Ibakuyumcu Arnaud
 * \author Voong Kwan
 * \author Ayutaya Rattanatray
 * \author Ruimy Benjamin
 * \version 1.0
 * \date 16 April 2016
 */

import Controleur.Controler;
import Vue.DialogBoxAsk.DialogBoxAV;
import Vue.DialogBoxAsk.DialogBoxSurv;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

/**
 * \class FenetreGUI
 * \brief Implementation of the IHM for the game
 */
public class FenetreGUI extends JFrame{

    // ATTRIBUTS //

    // Conteneur Haut (Tab bar)
    JTabbedPane containerHaut = new JTabbedPane();/**<Tab panel*/
    // Conteneur Bas (Action utilisateur)
    JPanel containerBas = new JPanel();/**<Panel for buttons buy,sell,control, remove controled*/
    // Conteneur (Action du marché)
    JPanel containerDroit = new JPanel();/**<Panel for the market's shares*/
    // Icone principal
    Image icon/**<Icon*/;
    // Les différents onglets
    JPanel portefeuille,favoris,historique, cours; /**<Differents tabs*/
    // Les affichages des onglets
    JTextArea portefeuilleTxt, favorisTxt, historiqueTxt, coursTxt, marcheTxt; /**<Differents textArea for tab bar*/
    // Boutons
    Bouton buttonJourSuiv, buttonAchat, buttonVente,
            buttonQuitter, buttonSurv, buttonNotSurv,
            buttonCours; /**<Buttons*/
    // Titre du marche
    JLabel titleMarche; /**<Market title*/
    // IDField
    JTextField IDField; /**<TextField for the asset's ID to show*/
    // Police du Jeu
    final Font police = new Font("Comics sans MS", Font.BOLD,16); /**<Font of the game*/


    // CONSTRUCTOR //

    /**
     * \fn FentreGUI(String marketName, String userName)
     * \brief Constructor
     *
     * \param String marketName : market's name
     * \param String userName : user's name
     */
    public FenetreGUI(String userName){

        // Définition de la fenetre //
        this.setTitle("ACVL : Simulation boursière (Joueur : " + userName + ")");
        this.setSize(1200,800);
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        try {
            icon = ImageIO.read(new File("src/Vue/images/icon.jpeg"));
        }catch(IOException e){
            e.printStackTrace();
        }
        this.setIconImage(icon);

        // Définitiond de la liste d'action (droite)
        containerDroit.setBackground(Color.BLACK);
        containerDroit.setLayout(new BorderLayout());
        JPanel containerDroitHaut = new JPanel();
        containerDroitHaut.setBackground(Color.BLACK);
        containerDroitHaut.setLayout(new BorderLayout());
        titleMarche = new JLabel();
        titleMarche.setForeground(Color.GREEN);
        titleMarche.setHorizontalAlignment(JLabel.CENTER);
        titleMarche.setFont(police);
        titleMarche.setPreferredSize(new Dimension(30,50));
        containerDroitHaut.add(titleMarche,BorderLayout.NORTH);
        buttonJourSuiv = new Bouton("Tour Suivant",police);
        buttonJourSuiv.setBackground(Color.BLACK);
        buttonJourSuiv.setPreferredSize(new Dimension(30,50));
        containerDroitHaut.add(buttonJourSuiv,BorderLayout.SOUTH);
        containerDroit.add(containerDroitHaut,BorderLayout.NORTH);
        buttonQuitter = new Bouton("Quitter",police);
        buttonQuitter.setPreferredSize(new Dimension(30,40));
        marcheTxt = new JTextArea(35,10);
        marcheTxt.setBackground(Color.BLACK);
        marcheTxt.setForeground(Color.green);
        marcheTxt.setEditable(false);
        JScrollPane scrollMarche = new JScrollPane(marcheTxt);
        containerDroit.add(scrollMarche,BorderLayout.CENTER);
        containerDroit.add(buttonQuitter,BorderLayout.SOUTH);

        // Definition de la tab bar
        containerHaut.setBackground(Color.LIGHT_GRAY);
        portefeuille = new JPanel();
        portefeuilleTxt = new JTextArea(35,60);
        portefeuilleTxt.setBackground(Color.LIGHT_GRAY);
        portefeuilleTxt.setEditable(false);
        JScrollPane scrollPort = new JScrollPane(portefeuilleTxt);
        scrollPort.setBackground(Color.LIGHT_GRAY);
        portefeuille.add(scrollPort);
        containerHaut.addTab("Portefeuille",new ImageIcon("src/Vue/images/portfolioIcon.png"),portefeuille,
                            "Actions présentes dans votre portefeuille");
        favoris = new JPanel();
        favorisTxt = new JTextArea(35,60);
        favorisTxt.setBackground(Color.LIGHT_GRAY);
        favorisTxt.setEditable(false);
        JScrollPane scrollFav = new JScrollPane(favorisTxt);
        favoris.add(scrollFav);
        containerHaut.addTab("Surveillées",new ImageIcon("src/Vue/images/lunetteIcon.png"),favoris,"Actions surveillées");
        historique = new JPanel();
        historiqueTxt = new JTextArea(35,60);
        historiqueTxt.setBackground(Color.LIGHT_GRAY);
        historiqueTxt.setEditable(false);
        JScrollPane scrollHist = new JScrollPane(historiqueTxt);
        historique.add(scrollHist);
        containerHaut.addTab("Historique",new ImageIcon("src/Vue/images/transactionIcon.png"),historique,"Historique de transaction de l'utilisateur");
        cours = new JPanel();
        cours.setLayout(new BorderLayout());
        coursTxt = new JTextArea(35,30);
        coursTxt.setBackground(Color.LIGHT_GRAY);
        coursTxt.setEditable(false);
        JScrollPane scrollCours = new JScrollPane(coursTxt);
        cours.add(scrollCours,BorderLayout.CENTER);
        JPanel panCoursID = new JPanel();
        panCoursID.setBackground(Color.LIGHT_GRAY);
        panCoursID.setLayout(new BorderLayout());
        panCoursID.setBorder(BorderFactory.createTitledBorder("Consulter le cours d'une action"));
        panCoursID.add(new JLabel("Saisir l'ID : "),BorderLayout.WEST);
        IDField = new JTextField();
        IDField.setPreferredSize(new Dimension(25,25));
        panCoursID.add(IDField,BorderLayout.CENTER);
        buttonCours = new Bouton("Valider",police);
        panCoursID.add(buttonCours,BorderLayout.EAST);
        cours.add(panCoursID,BorderLayout.SOUTH);
        containerHaut.addTab("Cours",new ImageIcon("src/Vue/images/coursIcon.png"),cours,"Cours d'une action depuis t=0");

        // Definition du container bas
        containerBas.setBackground(Color.DARK_GRAY);
        containerBas.setLayout(new BoxLayout(containerBas,BoxLayout.Y_AXIS));
        buttonAchat = new Bouton("Acheter",police);
        buttonVente = new Bouton("Vendre",police);
        JPanel containerButtonAV = new JPanel();
        containerButtonAV.setLayout(new BoxLayout(containerButtonAV,BoxLayout.X_AXIS));
        containerButtonAV.add(buttonAchat);
        containerButtonAV.add(buttonVente);
        containerButtonAV.setBackground(Color.DARK_GRAY);
        buttonSurv = new Bouton("Suivre",police);
        buttonNotSurv = new Bouton("Ne plus suivre",police);
        buttonSurv.setPreferredSize(new Dimension(168,27));
        JPanel containerButtonSurv = new JPanel();
        containerButtonSurv.setLayout(new BoxLayout(containerButtonSurv,BoxLayout.X_AXIS));
        containerButtonSurv.add(buttonSurv);
        containerButtonSurv.add(buttonNotSurv);
        containerButtonSurv.setBackground(Color.DARK_GRAY);
        containerBas.add(containerButtonAV);
        containerBas.add(containerButtonSurv);

        // Split des différents écrans
        JSplitPane split = new JSplitPane(JSplitPane.VERTICAL_SPLIT,
                                            containerHaut,containerBas);
        split.setDividerLocation(685);
        split.setEnabled(false);
        JSplitPane split2 = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,
                                            split,containerDroit);
        split2.setDividerLocation(900);
        split2.setEnabled(false);

        // Evenements lié aux boutons //
        buttonQuitter.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Controler.closeGUI();
            }
        });

        buttonAchat.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                DialogBoxAV db = new DialogBoxAV(null,"Acheter un actif",true,true);
                // Dans le cas où l'utilisateur a envoyé des datas
                if (db.isSendData()){
                    Controler.achat(db.getID(),db.getQte());
                }
                db.dispose();
            }
        });

        buttonVente.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                DialogBoxAV db = new DialogBoxAV(null,"Vendre un actif",true,false);
                // Dans le cas où l'utilisateur a envoyé des datas
                if (db.isSendData()){
                    Controler.vente(db.getID(),db.getQte());
                }
                db.dispose();
            }
        });

        buttonSurv.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                DialogBoxSurv db = new DialogBoxSurv(null,"Suivre un actif",true,true);
                // Dans le cas où l'utilisateur a envoyé des datas
                if (db.isSendData()){
                    Controler.surveiller(db.getID());
                }
                db.dispose();
            }
        });

        buttonNotSurv.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                DialogBoxSurv db = new DialogBoxSurv(null,"Ne plus suivre un actif",true,false);
                // Dans le cas où l'utilisateur a envoyé des datas
                if (db.isSendData()){
                    Controler.notSurveiller(db.getID());
                }
                db.dispose();
            }
        });

        buttonJourSuiv.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Controler.nextStep();
            }
        });

        buttonCours.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Dans le cas où rien est rempli
                try {
                    int ID = Integer.parseInt(IDField.getText());
                    Controler.consulterCours(ID);
                }catch (NumberFormatException ne){
                    new JOptionException("Erreur ID","Veuillez rentrer un ID valide");
                }
                IDField.setText("");
            }
        });

        // Affichage final
        this.setContentPane(split2);
        this.setVisible(true);
    }

    // METHODE D'UPDATE //

    /**
     * \fn void updatePortfolio(String str)
     * \brief Permit to update the display of the portfolio
     *
     * \param String str : Display of the portfolio
     */
    public void updatePortfolio(String str){
        portefeuilleTxt.setText(str);
    }
    /**
     * \fn void updateFavoris(String str)
     * \brief Permit to update the display of the controled shares
     *
     * \param String str : Display of the controled shares
     */
    public void updateFavoris(String str){
        favorisTxt.setText(str);

    }
    /**
     * \fn void updateHistorique(String str)
     * \brief Permit to update the display of the historic
     *
     * \param String str : Display of the historic
     */
    public void updateHistorique(String str){
        historiqueTxt.setText(str);
    }
    /**
     * \fn void updateCours(String str)
     * \brief Permit to update the display of share's price
     *
     * \param String str : Display of the portfolio
     */
    public void updateCours(String str){
        coursTxt.setText(str);
    }
    /**
     * \fn void updateMarche(String str)
     * \brief Permit to update the display of the market
     *
     * \param String str : Display of the market
     */
    public void updateMarche(String str){
        marcheTxt.setText(str);
    }
    /**
     * \fn void updateTitleMarche(String str)
     * \brief Permit to update the display of the market's title
     *
     * \param String str : The market's title
     */
    public void updateTitleMarche(String str){
        titleMarche.setText(str);
    }
}

