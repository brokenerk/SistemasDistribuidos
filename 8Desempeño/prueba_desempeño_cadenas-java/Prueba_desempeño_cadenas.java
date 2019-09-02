/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.util.Scanner;

/**
 *
 * @author marcus
 */
public class Prueba_desempeño_cadenas {

    public static void main(String[] args) {
    Scanner S = new Scanner(System.in);
    double n=1757600;
    String cadenota=" ";
    String[]  abc ={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    
     for(int j=0; j<n;j++)
     {
     for(int i=0 ; i<3;i++)
     {
     int p=(int) (Math.random()*26);
     cadenota=cadenota + abc[p]; 
     }
     cadenota=cadenota+" ";
     
     }
     
        System.out.println(cadenota);
     int buscador =0;
     int contador =0;
  String [] frag=cadenota.split("IPN");
buscador=frag.length-1;
    System.out.println("aparecio " + buscador);
    
    
        
    }
    
}
