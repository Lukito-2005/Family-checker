#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  string NameSurname[5], Surname[5], Name[5];
  int i, x, y, z;
  bool Comparison[5], ControlloNC[5], ControlloC[5], ContrChar = false;

  cout << "+----------------+" << endl
       << "FAMILY ORGANIZER" << endl
       << "+----------------+" << endl
       << endl;

  cout << "+---------------------------------------+" << endl
       << "-Inserisci il nome e cognome delle 5 persone" << endl;

  for (i = 0; i < 5; i++)
  {
    //--------------INPUT DEI NOMI--------------
    cout << endl
         << "-Persona N." << i + 1 << ":" << endl;
    getline(cin, NameSurname[i]);

    //--------------RIMOZIONE SPAZI ALL'INIZIO DI NameSurname--------------
    for (x = 0; x < NameSurname[i].length(); x++)
    {
      if (NameSurname[i][x] == 32)
      {
        NameSurname[i].erase(NameSurname[i].begin() + x);
        x--;
      }
      else
      {
        x = NameSurname[i].length();
      }
    }

    //--------------FINE RIMOZIONE SPAZI ALL'INIZIO DI NameSurname--------------

    //--------------INIZIO RIMOZIONE SPAZI ALLA FINE DI NameSurname--------------
    for (x = NameSurname[i].length() - 1; x >= 0; x--)
    {
      if (NameSurname[i][x] == 32)
      {
        NameSurname[i].erase(x);
      }
      else
      {
        x = -1;
      }
    }
    //--------------FINE RIMOZIONE SPAZI ALLA FINE DI NameSurname--------------

    //--------------INIZIO CONTROLLO CARRATTERI--------------
    for (x = 0; x < NameSurname[i].length(); x++) {
      if (NameSurname[i][x] >= 0 && NameSurname[i][x] < 32 || NameSurname[i][x] > 32 && NameSurname[i][x] < 65 || NameSurname[i][x] < 97 && NameSurname[i][x] > 90 || NameSurname[i][x] > 122) {
        ContrChar = true;
      }
    }
    //--------------FINE CONTROLLO CARRATTERI--------------

    //--------------CONTROLLO IN CASO DI STRINGA VUOTA O CARATTERI SPECIALI--------------
    while (NameSurname[i].empty() || ContrChar == true)
    {
      if (NameSurname[i].empty()) {
        cout << endl << "-La riga inserita e' vuota" << endl;
      } else {
        cout << endl << "-La riga contiene caratteri non consentiti" << endl;
      }
      ContrChar = false;
      cout << "-Reinserire il nome e cogmone N." << i + 1 << ":" << endl;
      getline(cin, NameSurname[i]);


      //--------------INIZIO RIMOZIONE SPAZI A NameSurname--------------
      for (x = 0; x < NameSurname[i].length(); x++)
      {
        if (NameSurname[i][x] == 32)
        {
          NameSurname[i].erase(NameSurname[i].begin() + x);
          x--;
        }
        else
        {
          x = NameSurname[i].length();
        }
      }
      //--------------FINE RIMOZIONE SPAZI A NameSurname--------------

      //--------------INIZIO RIMODIONE CARATTERI A NameSurname--------------
      for (x = NameSurname[i].length() - 1; x >= 0; x--)
      {
        if (NameSurname[i][x] == 32)
        {
          NameSurname[i].erase(x);
        }
        else
        {
          x = -1;
        }
      }
      //--------------FINE RIMODIONE CARATTERI A NameSurname--------------
    }

    transform(NameSurname[i].begin(), NameSurname[i].end(), NameSurname[i].begin(), ::tolower);
    Surname[i] = NameSurname[i].substr(NameSurname[i].find(" ", 0), NameSurname[i].length());
    Name[i] = NameSurname[i].substr(0, NameSurname[i].find(" ", 0));
    //--------------INIZIO TOGLI SPAZI A Name--------------
    for (x = 0; x < Name[i].length(); x++)
    {
      if (Name[i][x] == 32)
      {
        Name[i].erase(Name[i].begin() + x);
        x--;
      }
      else
      {
        x = Name[i].length();
      }
    }
    //--------------FINE TOGLI SPAZI A Name--------------

    //--------------INIZIO TOGLI SPAZI A Surname--------------
    for (x = 0; x < Surname[i].length(); x++)
    {
      if (Surname[i][x] == 32)
      {
        Surname[i].erase(Surname[i].begin() + x);
        x--;
      }
      else
      {
        x = Surname[i].length();
      }
    }
    //--------------FINE TOGLI SPAZI A Surname--------------

  }
  cout << "+---------------------------------------+" << endl
       << "FAMIGLIE" << endl;

  for (i = 0; i < 5; i++)
  {
    ControlloC[i] = false;
    ControlloNC[i] = false;
  }

  //--------------DISTRIBUZIONE PER FAMIGLIE DEI NOMI E COGNOMI--------------
  for (i = 0; i < 5; i++)
  {
    for (x = 0; x < 5; x++)
    {
      if (Surname[i] == Surname[x])
      {
        Comparison[x] = true;
      }
      else
      {
        Comparison[x] = false;
      }
    }

    for (z = 0; z < 5; z++)
    {
      if (Surname[i] == Surname[z] && i != z)
      {
        ControlloNC[z] = true;
      }
    }

    if (ControlloNC[i] == false)
    {
      cout << "+---------------------------------------+" << endl
           << "-Famiglia " << Surname[i] << ":" << endl;
    }

    for (y = 0; y < 5; y++)
    {
      if (Comparison[y] == true && ControlloC[y] == false)
      {
        ControlloC[y] = true;
        cout << "-" << Name[y] << " " << Surname[y] << endl;
      }
    }
  }

  return 0;
}
