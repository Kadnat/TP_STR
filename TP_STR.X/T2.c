#include "T2.h"

void tache2(void)
{
    alarme_batterie = 0;
    alarme_choc = 0;
    alarme_cle = 0;
    alarme_conducteur = 0;
    alarme_eau = 0;
    alarme_frein = 0;
    alarme_huile = 0;
    
    unsigned char cpt1=0,cpt2=0;

    while(1)
    {
        //while (PIR1bits.TX1IF==0);   TXREG1='B';while (TXSTA1bits.TRMT==0);

        //Gestion des alarmes

        alarme_frein = (~(FREIN_A_MAIN)) & 0x1;
        
        if(n_octet_badge == 0) alarme_cle = 1;
        else alarme_cle = 0;
        
        if(ANALOG_TEMP_EAU > 120) alarme_eau = 1;
        else alarme_eau = 0;
        
        if(ANALOG_TEMP_HUILE > 120) alarme_huile = 1;
        else alarme_huile = 0;     
        
        if(batterie < 15) alarme_batterie = 1;
        else alarme_batterie = 0;
        
        alarme_conducteur = (~(SIEGE)) & 0x1;
        
        alarme_choc = (~(CHOC)) & 0x1;
        
        if(alarme_frein || alarme_eau || alarme_huile || alarme_batterie || alarme_cle || alarme_conducteur)
        {
            if(cpt1==0)
            {
                Tick_SaveT2 = Tick_Count;
                cpt1 = 1;
            }
            if(Tick_Count > Tick_SaveT2 + 10)
            {
                if(cpt1==1)
                {
                    Tick_SaveT2 = Tick_Count;
                    if(vitesse >0)vitesse -= 1;
                    else
                    {
                        vitesse = 0;
                        cpt1 = 0;
                    }
                    
                }
                
            }
            
        }
        
        if(alarme_cle)
        {
            if(cpt2==0)
            {
                Tick_SaveT2 = Tick_Count;
                cpt2 = 1;
            }
            if(Tick_Count < Tick_SaveT2 + 100)
            {
                if(cpt2==1)
                {

                        vitesse = 0;
                        cpt2 = 0;
                }
                    
                }
                
            
        }
        

        //while (PIR1bits.TX1IF==0);   TXREG1='H';while (TXSTA1bits.TRMT==0);


    }
}
