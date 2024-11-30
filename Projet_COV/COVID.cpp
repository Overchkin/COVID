//Algorithme de d�cision du COVID-2019
#include<iostream>
using namespace std;

/*Fonction pour valider et convertir la r�ponse � l'utilisateur.
Type de retour de la fonction. La fonction renverra une valeur bool�enne (true ou false)*/
bool reponse(const string& message)
{
	//D�claration de  variable de type cha�ne de carat�re
	char reponse;
	//Affiche le texte pass� en param�tre (message) dans la console
	cout << message;
	cin >> reponse;
	//Conversion de la r�ponse en majuscule
	reponse = toupper(reponse);
	/*utilisation de condition if qui retourne vrai lorsque la r�ponse est oui puis retourne faux lorsque la r�ponse est non
	et retourne un message d'erreur lorsqu'on saisie autre lettre que O ou N*/
	if (reponse == 'O')
	{
		return true;
	}
	else if (reponse == 'N')
	{
		return false;
	}
	else
	{
		cout << "Saisie invalide.Veuillez entrer O pour oui et N pour non" << endl;
		exit(1);
	}
}

int main()
{
	cout << "SUJET VOYAGEUR VENANT DE PAYS TOUCHE" << endl;
	cout << endl;
	//Appelle la fonction `reponse` pour demander si le pays a notifi� un cas confirm�.
	bool O = reponse("Pays ayant notifie un cas confirme (O pour Oui, N pour Non): ");
	cout << endl;
	//V�rifie si la r�ponse est "Oui" (true).
	if (O)  
	{
		//Si la r�ponse est "Oui", affiche le message ci-dessous.
		cout << "Cas alerte" << endl;
		//Saut de lignes
		cout << endl;

		// D�claration d'une variable bool�enne pour v�rifier la pr�sence de signes (fi�vre, toux, rhume, �ternuement, fatigue)
		bool Signes = ("Presence de signes, fievre, toux, rhume, eternuement, fatigue (O pour Oui et N pour Non)");
		
		// V�rifie si aucun signe n'est pr�sent
		if (!Signes)
		{
			// Si aucun signe, le cas est une alerte sans signes
			cout << "Cas alerte sans signes" << endl;

			// D�claration d'une variable bool�enne pour �valuer le risque �lev� ou mod�r�
			bool casSignes = ("Cas avec risque eleve ou modere (O pour Oui et N pour Non)");

			// Si le risque est �lev� ou mod�r�, mettre en quarantaine avec suivi
			if (casSignes)
			{
				cout << "Mise en quarantaine avec suivi" << endl;

				bool Apparition = ("Apparition de signes dans les 14 jours de suivi");

				// Si des signes apparaissent, le cas devient suspect et n�cessite un transfert
				if (Apparition)
				{
					cout << "Cas Suspect" << endl;
					cout << "Transfert au site de prise en charge" << endl;
				}

				// Si aucun signe n'appara�t, sortie apr�s 14 jours et lev�e de l'auto-isolement
				else
				{
					cout<<"Sortie" << endl;
					cout << "Levee l'auto-isolement et de mise en quarantaine apr�s 14 jours" << endl;
				}
			}

			// Si le risque est faible, mise en auto-isolement avec suivi
			else
			{
				cout << "Cas avec risque faible" << endl;
				cout << "Auto-isolement avec suivi" << endl;

				// V�rification de l'apparition de signes dans les 14 jours de suivi
				bool Apparition = ("Apparition de signes dans les 14 jours de suivi");

				if (Apparition)
				{
					// Si des signes apparaissent, le cas devient suspect et n�cessite un transfert
					cout << "Cas suspect" << endl;
					cout << "Transfert au site de prise en charge" << endl;
				}
				else
				{
					// Si aucun signe n'appara�t, sortie apr�s 14 jours et lev�e de l'auto-isolement
					cout<<"Sortie" << endl;
					cout<<"Levee l'auto-isolement et la mise en quarantaine apres 14 jours" << endl;
				}
			}
		}
		else
		{
			// Si des signes sont pr�sents d�s le d�part, le cas est suspect et n�cessite un transfert imm�diat
			cout << "Cas suspect" << endl;
			cout << "Transfert au site de prise en charge" << endl;
		}
	}
	//Si la r�ponse est "Non" (false).
	else
	{
		//Affiche que le sujet n�cessite une exploration suppl�mentaire.
		cout << "Sujet a explorer" << endl;
		cout<< endl;
		//Appelle la fonction `reponse` pour demander s'il y a pr�sence de signes cliniques.
		// Stocke la r�ponse sous forme de bool�en.
		bool signes = reponse("Presence de signes (O pour Oui, N pour Non): ");
		cout << endl;
		// V�rifie si **aucun signe** n'est pr�sent (signes == false).
		if (!signes)
		{
			// Si aucun signe n'est pr�sent, affiche que le sujet ne pr�sente pas de risque �vident et peut rentrer pour repos.
			cout << "Sujet sans risque evident" << endl;
			cout << "Sortie avec recommandation de repos" << endl;
		}
		// Si des signes sont pr�sents (signes == true).
		else
		{
			// Indique que le sujet doit �tre explor� davantage et sugg�re de nouveau d�pistage
			cout << "Sujet a explorer" << endl;
			cout << "Reprendre depistage" << endl;
			cout << endl;
			// Appelle la fonction `reponse` pour demander si le sujet a visit� un pays touch� dans les 14 derniers jours.
			// La r�ponse est stock�e sous forme de bool�en.
			bool depistage = reponse("Visite de l'un des pays toucher lors des 14 derniers jours (O pour Oui, N pour Non): ");
			cout << endl;

			// V�rifie si le sujet a visit� un pays touch� r�cemment (depistage == true).
			if (depistage)
			{
				// Affiche que le sujet est un cas suspect et indique un transfert vers un site de prise en charge.
				cout << "Cas suspect" << endl; 
				cout << "Transfert au site de prise en charge" << endl;
			}

			// Si le sujet n'a pas visit� un pays touch� (depistage == false).
			else
			{
				// Indique que le sujet ne pr�sente pas de risque �vident et recommande au sujet de sortie avec du repos.
				cout << "Sujet sans risque evident" << endl;
				cout << "Sortie avec recommandation de repos" << endl;
			}
		}
	}

	return 0;
}