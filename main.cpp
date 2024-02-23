#include "fun.cpp"

int main (){
  //ifstream fd ("studentai10000.txt");
  //ifstream fd ("studentai100000.txt");
    ifstream fd ("studentai1000000.txt"); 
    ofstream fr ("kursiokai.txt");

    try {
        ifstream fd ("studentai10000.txt");
        if (!fd.is_open()){
            throw runtime_error ("Nepavyko atidaryti duomenu failo");
        }
        ofstream fr ("kursiokai.txt");
        if (!fr.is_open()){
            throw runtime_error ("Nepavyko atidaryti rezultatu failo");
        }
    
    vector <studentas> A;
    int n; int pasirinkimas;
    while (true){
        cout << "Pasirinkite norima veiksma: " << endl;
        cout << "1. Ivesti duomenis ranka" << endl;
        cout << "2. Nuskaityti duomenis is failo" << endl;
        cout << "3. Generuoti pazymius" << endl;
        cout << "4. Generuoti studentu vardus ir pavardes" << endl;
        cout << "5. Rusiuoti pagal pasirinktus parametrus" << endl;
        cout << "6. Baigti programa" << endl;
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
                A.clear();
                skaitymasTeksto (A);
                skaiciavimas (A);
                spausdintiTeksto (A);
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
                cout << "Pasirinkite rusiavimo kriterijus: " << endl;
                cout << "1. Pagal varda" << endl;
                cout << "2. Pagal pavarde" << endl;
                cout << "3. Pagal galutini (vidurkis)" << endl;
                cout << "4. Pagal galutini (mediana)" << endl;
                int rusiavimas;
                cin >> rusiavimas;

                switch (rusiavimas) {
                    case 1:
                        sort(A.begin(), A.end(), pagalVarda);
                        break;
                    case 2:
                        sort(A.begin(), A.end(), pagalPavarde);
                        break;
                    case 3:
                        sort(A.begin(), A.end(), pagalVidurki);
                        break;
                    case 4:
                        sort(A.begin(), A.end(), pagalMediana);
                        break;
            }
            spausdinti (A);
            spausdintiTeksto(A);
            break;
                
            }
            case 6:
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
 }
    catch (const exception & e) {
        cout << e.what () << endl;
    }
    return 0;
}