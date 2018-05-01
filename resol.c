int resolution(void) /* fct qui resout la grille */
{
int V,N, Ok, n, T[NBC];
char * NewM;
   while(1) {
     for (V=1; V<NBC+1; V++) {/*on prend les valeurs les unes apres les autres*/
       Ok=0;
       for (N=1; N<NBC+1; N++) { /* on essaie de traiter les colonnes */
          if (estPresentCol(V,N)) continue;
          /* on cherche si il est possible de mettre V dans la colonne N */
          n = nbCasPossCol(V, N, T);
          if (n==0) retourMatPrec(); /* on revient en arriere */
          if (n==1) { /* on est certain que la valeur est bonne */
             rempliMat(*T+1,N,V);
             Ok=1; break; /* signifie que l'on a trouve ! */ 
          }
       }
       /* continuOuPas("Passage a la valeur suivante"); */
       if (Ok) break;
     }
     /* est ce que l'on repart ou pas ? */
     if (Ok==0) { /* on ne peut plus rien remplir ! solution avec 50% chance */
        for (V=1; V<NBC+1; V++) { /*on reprend toutes les valeurs */
          for (N=1; N<NBC+1; N++) { /* on essaie de traiter les colonnes */
             if (estPresentCol(V,N)) continue;
             /* on cherche si il est possible de mettre V dans la colonne N */
             n = nbCasPossCol(V, N, T);
             if (n==0) retourMatPrec(); /* on revient en arriere */
             if (n==2) { /* on utilise les cas 50-50 */
                rempliMat(*T+1,N,V); /* on met le 1er cas dans la mat.actuelle*/
                NewM = new_matrice(); /* creation de la nouvelle matrice */
                chaine_ajout((void*)NewM);
                AdM = NewM;
                rempliMat(*(T+1)+1,N,V); /*le 2em cas dans la nouv.mat.actuel.*/
                Ok=1; break; /* signifie que l'on a trouve ! */ 
             }
          }
        }
     }
     if (Ok==0) break;
   }
}
