/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author marcus
 */
public class Numericos {
    public static void main(String[] args) {
        double i=0, seno,coseno,tangente,logaritmo,raiz=0;
       
        while (i<1757600.0)
        {
           seno= Math.sin(i);
           coseno=Math.cos(i);
           tangente=Math.tan(i);
           logaritmo=Math.log(i);
           raiz=Math.sqrt(i);
           i++;
        }
        System.out.println("acabe");
        
    }
    
    
}
