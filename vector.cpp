#include <bits/stdc++.h>
using namespace std;

const int MAX_ND_SIZE = 500;
const int MAX_STUDENTS = 500;
struct studentas
{
    string vardas;
    string pavarde;
     vector <int> nd;
     int egz;
     double balas;
     double vid;
     double mediana;
};


void skaitymas (vector <studentas> & A, int n);
void skaitymasTeksto (vector <studentas> & A);
void spausdinti (const vector <studentas> & A);
void skaiciavimas (vector <studentas> & A);
void generavimasPazymiu (vector <studentas> & A, int n);
void generavimasPazymiuCase2 (vector <studentas> & A);
void generavimasStudentu (vector <studentas> & A, int n);
bool isValidName(const string &name);

int main (){

    ifstream fd ("studentai10000.txt");
    ofstream fr ("kursiokai.txt");

    vector <studentas> A;
    int n; int pasirinkimas;
    while (true){
        cout << "Pasirinkite norima veiksma: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Nuskaityti duomenis is failo" << endl;
        cout << "3. Generuoti pazymius" << endl;
        cout << "4. Generuoti studentu vardus ir pavardes" << endl;
        cout << "5. Baigti programa" << endl;
        cin >> pasirinkimas;

        switch (pasirinkimas){
            case 1:
            {
                skaitymas (A, n);
                skaiciavimas (A);
                spausdinti (A);
                break;
            }
            case 2:
            {
                skaitymasTeksto (A);
                skaiciavimas (A);
                spausdinti (A);
                break;
            }
            case 3:
            {
                int n2;
                cout << "Iveskite zmoniu skaiciu" << endl;
                cin >> n2;
                for (int i = 0; i < n2; i++)
            {
                studentas student;
                bool valid_names;
                do
                {
                    cout << "Iveskite savo varda" << endl;
                    cin >> student.vardas;
                    cout << "Iveskite savo pavarde" << endl;
                    cin >> student.pavarde;
                    valid_names = isValidName(student.vardas) && isValidName(student.pavarde);
                    if (!valid_names)
                    {
                        cout << "Netinkami vardai. Bandykite is naujo." << endl;
                    }
                } while (!valid_names);
                 A.push_back(student);
            }
                generavimasPazymiuCase2(A);
                skaiciavimas (A);
                spausdinti (A);
                break;
            }
            case 4:
            {
                int n3 = rand() % (MAX_STUDENTS + 1);
                A.clear();
                generavimasPazymiu (A, n3);
                generavimasStudentu (A, n3);
                skaiciavimas (A);
                spausdinti (A);
                break;
            }
            case 5:
            {
                cout << "Programos pabaiga" << endl;
                return 0;
            }
            default:
            {
                cout << "Neteisingas pasirinkimas. Bandykite dar karta" << endl;
                break;
            }
        }
    }

return 0;
}
void skaitymas (vector <studentas> & A, int n)
{  
    cin >> n;
      for (int i = 0; i < n; i++)
    {
         studentas student;
        
        cin >> student.vardas;
        cout << "Iveskite savo pavarde " << endl;
        cin >> student.pavarde;
        bool valid_vardas = isValidName(student.vardas);
        bool valid_pavarde = isValidName(student.pavarde);
        if (!valid_vardas || !valid_pavarde)
        {
            cout << "Netinkami vardai. Bandykite is naujo." << endl;
            i--;
            continue;
        }
        cout << "Iveskite egzamino rezultatus " << endl;
        cin >> student.egz;
        cout << "Iveskite namu darbu tarpinius rezultatus (baigti ivesdami -1)" << endl;
        int nd;
        while (cin >> nd && nd != -1)
        {
            student.nd.push_back(nd);
        }
        A.push_back(student);
    }
}
void skaitymasTeksto (vector <studentas> & A)
{
    ifstream fd ("studentai10000.txt");
    string eil;
    getline(fd, eil);
    while (getline(fd, eil)){
        stringstream ss(eil);
        studentas student;
        ss >> student.vardas >> student.pavarde;
        int paz;
        while (ss >> paz){
            student.nd.push_back(paz);
        }
        ss >> student.egz;
        A.push_back(student);
    }
    fd.close();

}
void skaiciavimas (vector <studentas> & A)
{ 
   for (int i = 0; i < A.size(); i++ )
    {
        sort(A[i].nd.begin(), A[i].nd.end());
        int size = A[i].nd.size();
        if (size % 2 == 0)
        {
            A[i].mediana = (A[i].nd[size / 2 - 1] + A[i].nd[size / 2]) / 2.0;
        }
        else
        {
            A[i].mediana = A[i].nd[size / 2];
        }
        double sum = accumulate(A[i].nd.begin(), A[i].nd.end(), 0);
        if (size > 0)
        {
            A[i].vid = sum / size;
            A[i].balas = 0.4 * A[i].vid + 0.6 * A[i].egz;
        }
        else
        {
            A[i].vid = A[i].egz;
            A[i].balas = A[i].vid;
            A[i].mediana = A[i].vid;
        }
    }
}
void spausdinti (const vector <studentas> & A)
{
    ofstream fr ("kursiokai.txt");
    fr << left << setw(10) << "Pavarde " << setw(15) << "Vardas " << setw(15) << "Galutinis (Vid.) " << " " << "/ Galutinis (Med.)" << endl;
    fr << "----------------------------------------------------" << endl;
    for (int i = 0; i < A.size(); i++){
     fr << left << setw(10) << A[i].vardas << setw(15) << A[i].pavarde << fixed << setprecision(2) << setw(15) << A[i].balas << setw(10) << A[i].mediana << endl;
    }
}
void generavimasPazymiu(vector<studentas>& A, int n2) {
    srand(time(0));
    A.clear();
    for (int i = 0; i < n2; i++)
    {
        studentas student;
        int nd_count = rand() % (MAX_ND_SIZE + 1);
        for (int j = 0; j < nd_count; j++)
        {
            student.nd.push_back(rand() % 11);
        }
        student.egz = rand() % 11;
        A.push_back(student);
    }
}
void generavimasPazymiuCase2 (vector <studentas> & A)
{
    srand(time(0));
    for (int i = 0; i < A.size(); i++){
        int nd_count = rand() % (MAX_ND_SIZE + 1);
        for (int j = 0; j < nd_count; j++){
            A[i].nd.push_back(rand() % 11);
        }
        A[i].egz = rand() % 11;
    }
}
void generavimasStudentu(vector<studentas>& A, int n) {
   
    srand(time(0));

    string vardai[] = {"Rokas", "Mantas", "Pijus", "Laurynas", "Ignas", "Gabriele", "Ugne", "Kamile", "Rugile", "Roberta"};
    string pavardes[] = {"Gilys", "Globys", "Bogusis", "Dulskis", "Maliauka", "Skirmantaite", "Mockute", "Zobelaite", "Macaite", "Jurpalyte"};

    for (int i = 0; i < A.size(); i++)
    {
        studentas student;
       A[i].vardas = vardai[rand() % 10];
       A[i].pavarde = pavardes[rand() % 10];
    }
}
bool isValidName(const string &name)
{
    for (char c : name)
    {
        if (!isalpha(c) && c != ' ')
        {
            return false;
        }
    }
    return true;
}