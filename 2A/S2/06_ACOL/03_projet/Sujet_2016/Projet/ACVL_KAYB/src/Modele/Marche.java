package Modele; /**
 * \file Modele.Marche.java
 * \brief Implementation of the class Modele.Marche
 * \author Ibakuyumcu Arnaud
 * \author Voong Kwan
 * \author Ayutaya Rattanatray
 * \author Ruimy Benjamin
 * \version 1.0
 * \date 10 April 2016
 */

import Modele.Actions.Action;

import java.sql.*;
import java.text.DecimalFormat;

/**
 * \class Modele.Actions.ListeDAction.Modele.Marche
 * \brief Representation of the market
 * \brief Patron de conception singleton
 *
 * \details Contain the spot of each asset
 */
final public class Marche {

    // ATTRIBUTS //

    private String nom; /**< Market's name */
    private static int tourCour; /**< Time */
    private static int nombreActions; /**< Number of assets in the market*/
    private static Action[] actions; /**< Assets contained in the market */
    private static double[] cours; /**< Asset's value at t=tourCour*/
    private static Connection connection; /**< The connection to the DataBase*/

    // CONSTRUCTOR //

    /**
     * \fn Modele.Marche(String nom, int tourCour,int nombreActions,Connection connection)
     * \brief Constructor of a market
     *
     * \param String nom : Market's name
     * \param int tourCour : The current round
     * \param int nombreActions : The number of action in the market
     * \param connection : The connection to the database
     *
     * \throws Exception in the case of null connection
     */
    public Marche(String nom, int tourCour,int nombreActions,Connection connection)throws Exception{
        int i = 0;
        Marche.connection = connection;
        if (connection == null){
            throw new Exception("|| Exception ");
        }
        try{
            actions = new Action[nombreActions];
            cours = new double[nombreActions];
            Statement stmt = connection.createStatement();
            String getActions = "SELECT * FROM ACTION ORDER BY IDaction";
            ResultSet rsActions = stmt.executeQuery(getActions);
            while(rsActions.next() && i<nombreActions) {
                cours[i] = rsActions.getInt("VALUE1");
                actions[i] = new Action(rsActions.getInt("IDACTION"),rsActions.getInt("QUANTITY"),
                        rsActions.getString("NAME"),rsActions.getInt("VALUE1"));
                i++;
            }
            Marche.nombreActions = nombreActions;
            Marche.tourCour = tourCour;
            this.nom = nom;
        } catch (Exception e){
            System.err.println("FAIL");
            e.printStackTrace();
        }
    }

    // GETTERS //

    public String getNom() {
        return nom;
    }

    public static int getTourCour() {
        return tourCour;
    }

    public static Connection getConnection(){
        return connection;
    }

    // METHODS //

    /**
     * \fn void nextLap()
     * \brief Permit to go to the next round
     */
    public void nextLap(){
        tourCour++;
        int i = 0;
        try{
            Statement stmt = connection.createStatement();
            String getActions = "SELECT * FROM ACTION ORDER BY IDaction";
            ResultSet rsActions = stmt.executeQuery(getActions);
            while(rsActions.next()) {
                cours[i] = rsActions.getFloat("VALUE" + (Marche.getTourCour() + 1));
                i++;
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }

    /**
     * \fn double getValeur(int IDAction)
     * \brief Permit to obtain the spot value of an asset
     *
     * \param IDAction : The asset identifiant
     *
     * \return double : The value of the asset
     */
    public static double getValeur(int IDAction){
        return cours[IDAction];
    }

    /**
     * \fn String getNom(int IDAction)
     * \brief Permit to obtain the name of an asset
     *
     * \param int IDAction : The asset identifiant
     *
     * \return String : The name of the asset
     */
    public static String getNom(int IDAction) throws Exception{
        if(IDAction >= Marche.nombreActions){
            throw new Exception("L'ID est inexistant \n");
        }
        return actions[IDAction].getNom();

    }

    /**
     * \fn String toString()
     * \brief Permit to describe the market
     *
     * \return String : The description
     */
    @Override
    public String toString(){
        DecimalFormat df = new DecimalFormat("0.0##");
        String s = "\n\tIl y a " + nombreActions + " actions\n";
        for (Action i : actions){
            s += "\n\n  ID " + i.getIDAction();
            s += " : " + i.getNom();
            s += "\n----------------------------------";
            s += "\n  Valeur : " + df.format(i.getValeur());
            s += "\n  Evolution : " + df.format(i.getEvolution()) + " %";
            s += "\n  Plus-Value => " + df.format(i.getPlusValue()) + "\n";
        }
        return s;
    }
}
