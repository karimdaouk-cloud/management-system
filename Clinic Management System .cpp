#include<iostream>
#include<ctime> // library to get time

using namespace std;

const int NoP = 1000; // Number of Patients 

char lastName[NoP][80]; // char array for last name 
char firstName[NoP][80]; // char array for first name 
char fatherName[NoP][80]; // char array for father name
char birthdayDate[NoP][80]; // char array for birthdate
char phoneNumber[NoP][20]; // char array for phone number
char address[NoP][500]; // char array for address
bool generalAnamnesis[10][NoP]; // insert anamnesis 

int iD[NoP] = { 0 }; // array to store patient id
bool sexe[NoP]; // char array for sex male or female (True = male ; false = female)

// array to store birth date 
int birthDay[NoP] = { 0 };
int birthMonth[NoP] = { 0 };
int birthYear[NoP] = { 0 };

int age[NoP] = { 0 }; // array to store patient age 

// arrays for intraoral examination
char softTissue[80][NoP];//char array for soft tissue
char teeth[80][NoP];// char array for teeth
char articulation[80][NoP]; //char array for articulation
char extraction[80][NoP];//char array for extraction
char localIlness[80][NoP];//char array for local ilness

int patient = 0; // patient counter 


//functions for intraoral examination

//function to add soft tissue 
void InpsoftTissue(char softTissue[][NoP], int patient) {
    cout << "Enter Soft Tissue Problems: ";
    cin.ignore();
    cin.getline(softTissue[patient], 80);
}
//function to add Teeth
void InpTeeth(char teeth[][NoP], int patient) {
    cout << "Enter Teeth Problems: ";
     cin.ignore();
     cin.getline(teeth[patient], 80);

}
//function to add articulation 
void InpArticulation(char articulation[][NoP], int patient) {
    cout << "Enter Articulation Problems: ";
    cin.ignore();
    cin.getline(articulation[patient], 80);
}
//function to add extraxtion
void InpExtraction(char extraction[][NoP], int patient) {
    cout << "Enter Extraction Problems: ";
    cin.ignore();
    cin.getline(extraction[patient], 80);
}
//function to add localIlness
void InpLocalIlness(char localIlness[][NoP], int patient) {
    cout << "Enter localIlness Problems: ";
    cin.ignore();
    cin.getline(localIlness[patient], 80);
}
//function to input all intraoral examination 
void InpintraOralexamination() {
    cout << "IntraOral Examination." << endl;
    InpsoftTissue(softTissue, patient);
    InpTeeth(teeth, patient);
    InpArticulation(articulation, patient);
    InpExtraction(extraction, patient);
    InpLocalIlness(localIlness, patient);
}


// function to add last name of a new patient 
void InplastName(char lastName[][80], int patient) {
    cout << "Enter the Last name of patient ID#" << patient + 1000 << ": ";
    cin >> lastName[patient];
}

// function to add first name of a new patient
void InpfirstName(char firstName[][80], int patient) {
    cout << "Enter the First name of patient ID#" << patient + 1000 << ": ";
    cin >> firstName[patient];
}

// function to set patient number to its corresponding id 
void idPlacer(int iD[], int patient) {
    iD[patient] = patient;
}

// function to add father's name of a new patient 
void InpfatherName(char fatherName[][80], int patient) {
    cout << "Enter Father's name of patient ID#" << patient + 1000 << ": ";
    cin >> fatherName[patient];
}

// function to add patient's birthday
void InpbirthdayDate(int birthDay[], int birthMonth[], int birthYear[], int patient) {
    cout << "Enter the Date of the patient ID# " << patient + 1000 << " using the following format DD/MM/YYYY: ";
    cin >> birthDay[patient];
    cin.ignore();
    cin >> birthMonth[patient];
    cin.ignore();
    cin >> birthYear[patient];
}

// function to calculate patient's age

void GetpatientAge(int birthDay[], int birthMonth[], int birthYear[], int age[], int patient) {

    // Get the current date
    time_t now = time(0);
    tm currentDate;
    localtime_s(&currentDate, &now);
    int currentDay = currentDate.tm_mday;
    int currentMonth = currentDate.tm_mon + 1;
    int currentYear = currentDate.tm_year + 1900;

    int day = birthDay[patient];
    int month = birthMonth[patient];
    int year = birthYear[patient];

    int ages = currentYear - year;

    // Check if patient's birthday has already occurred this year
    if (month > currentMonth || (month == currentMonth && day > currentDay)) {
        ages--;
    }

    age[patient] = ages;
}

// function to add patient's address
void Inpaddress(char address[][500], int patient) {
    cout << "Enter Address of patient ID#" << patient + 1000 << ": ";
    cin.ignore();
    cin.getline(address[patient], 500);
}

// function to add patient's phone number 
void InpphoneNumber(char phoneNumber[][20], int patient) {
    cout << "Enter Phone Number of patient ID#" << patient + 1000 << ": ";
    //cin >> phoneNumber[patient];
    cin.ignore();
    cin.getline(phoneNumber[patient], 20);
}

// function to add patient's gender
void Inpsexe(bool sexe[], int patient) {
    char temp;

    cout << "Enter the gender of patient ID#" << patient + 1000 << ". M for male, F for female: ";
    cin >> temp;

    while (temp != 'M' && temp != 'm' && temp != 'F' && temp != 'f') {
        cout << "Invalid Letter" << endl;
        cout << "Enter the gender of patient ID#" << patient + 1000 << ". M for male, F for female: ";
        cin >> temp;
    }


    if (temp == 'M' || temp == 'm')
        sexe[patient] = true;   // True for Male 
    else if (temp == 'F' || temp == 'f')
        sexe[patient] = false; // fasle for female 
}

// function to print patient details
void printPatientDetails(int id) {
    cout << "Id# " << iD[id - 1000] + 1000 << endl;
    cout << "First Name: " << firstName[id - 1000] << endl;
    cout << "Father's Name: " << fatherName[id - 1000] << endl;
    cout << "Last Name: " << lastName[id - 1000] << endl;
    cout << "Gender: " << (sexe[id - 1000] ? "Male" : "Female") << endl;
    cout << "Age: " << age[id - 1000] << endl;
    cout << "Birthday: " << birthDay[id - 1000] << "/" << birthMonth[id - 1000] << "/" << birthYear[id - 1000] << endl;
    cout << "Phone Number: " << phoneNumber[id - 1000] << endl;
    cout << "Address: " << address[id - 1000] << endl;
    cout << endl;
    cout << endl;

    cout << "General Anamnesis:" << endl;
    cout << endl;
    cout << "Heart Disease: ";
    if (generalAnamnesis[0][id - 1000] == false)
        cout << "No" << endl;
    else if (generalAnamnesis[0][id - 1000] == true)
        cout << "Yes" << endl;
    cout << "Allergy: ";
    if (generalAnamnesis[1][id - 1000] == false)
        cout << "No" << endl;
    else if (generalAnamnesis[1][id - 1000] == true)
        cout << "Yes" << endl;
    cout << "General Ilness: ";
    if (generalAnamnesis[2][id - 1000] == false)
        cout << "No" << endl;
    else if (generalAnamnesis[2][id - 1000] == true)
        cout << "Yes" << endl;
    cout << endl;
    cout << "Lung Ilness: ";
    if (generalAnamnesis[3][id - 1000] == false)
        cout << "No" << endl;
    else if (generalAnamnesis[3][id - 1000] == true)
        cout << "Yes" << endl;
    cout << "Hormones Ilness: ";
    if (generalAnamnesis[4][id - 1000] == false)
        cout << "No" << endl;
    else if (generalAnamnesis[4][id - 1000] == true)
        cout << "Yes" << endl;

    cout << "Diabetes: ";
    if (generalAnamnesis[5][id - 1000] == false)
        cout << "No" << endl;
    else if (generalAnamnesis[5][id - 1000] == true)
        cout << "Yes" << endl;

    cout << "Heredital Ilness: ";
    if (generalAnamnesis[6][id - 1000] == false)
        cout << "No" << endl;
    else if (generalAnamnesis[6][id - 1000] == true)
        cout << "Yes" << endl;
    cout << endl;
    cout << endl;
    cout << "ExtraOral Examination: " << endl;
    cout << endl;
    cout << "Symmetry: ";
    if (generalAnamnesis[7][id - 1000] == false)
        cout << "No" << endl;
    else if (generalAnamnesis[7][id - 1000] == true)
        cout << "Yes" << endl;
    cout << "ATM (Temporomandibular Articulation): ";
    if (generalAnamnesis[8][id - 1000] == false)
        cout << "No" << endl;
    else if (generalAnamnesis[8][id - 1000] == true)
        cout << "Yes" << endl;
    cout << "Pain: ";
    if (generalAnamnesis[9][id - 1000] == false)
        cout << "No" << endl;
    else if (generalAnamnesis[9][id - 1000] == true)
        cout << "Yes" << endl;
    cout << endl;
    cout << "IntraOral Examination: " << endl;
    cout << endl;
    cout << "Soft Tissue: " << softTissue[id - 1000] << endl;
    cout << "Teeth: " << teeth[id - 1000] << endl;
    cout << "Articulation: " << articulation[id - 1000] << endl;
    cout << "Extraction: " << extraction[id - 1000] << endl;
    cout << "Local Ilness: " << localIlness[id - 1000] << endl;

}

// function to list all patients 
void listPatients(int patient) {
    cout << "List of Patients:" << endl;
    cout << endl;

    for (int i = 0; i < patient; i++) {

        cout << "Patient ID#" << iD[i] + 1000 << endl;
        cout << "First Name: " << firstName[i] << endl;
        cout << "Father's Name: " << fatherName[i] << endl;
        cout << "Last Name: " << lastName[i] << endl;
        cout << endl;

    }
}

//function to display welcome message
void displayWelcomeMessage() {
    const string clinicName = "Dental Clinic Management Software";
    const int frameWidth = 60;

    // Display the top border
    cout << string(frameWidth, '*') << endl;

    // Display the empty line
    cout << "*" << string(frameWidth - 2, ' ') << "*" << endl;

    // Display the welcome message
    int padding = (frameWidth - clinicName.length()) / 2;
    cout << "*";
    cout << string(padding, ' ') << clinicName << string(padding + frameWidth % 2 - 1, ' ');
    cout << "*" << endl;

    // Display the empty line
    cout << "*" << string(frameWidth - 2, ' ') << "*" << endl;

    // Display the bottom border
    cout << string(frameWidth, '*') << endl;

    cout << endl;
}

// function to input general anamnesis
void inpgeneralAnamnesis(bool generalAnamnesis[][NoP], int patient) {
    char temp = ' ';

    cout << "Enter patient anamnesis." << endl;
    cout << "Y for yes, N for no." << endl;

    //input Hear Disease
    do {
        cout << "Heart Disease: ";
        cin >> temp;

        if (temp == 'y' || temp == 'Y')
            generalAnamnesis[0][patient] = true;
        else if (temp == 'n' || temp == 'N')
            generalAnamnesis[0][patient] = false;
    } while (temp != 'y' && temp != 'Y' && temp != 'N' && temp != 'n');

    //input Allergy
    do {
        cout << "Allergy: ";
        cin >> temp;

        if (temp == 'y' || temp == 'Y')
            generalAnamnesis[1][patient] = true;
        else if (temp == 'n' || temp == 'N')
            generalAnamnesis[1][patient] = false;
    } while (temp != 'y' && temp != 'Y' && temp != 'N' && temp != 'n');

    //input general Illness
    do {
        cout << "General Ilness: ";
        cin >> temp;

        if (temp == 'y' || temp == 'Y')
            generalAnamnesis[2][patient] = true;
        else if (temp == 'n' || temp == 'N')
            generalAnamnesis[2][patient] = false;
    } while (temp != 'y' && temp != 'Y' && temp != 'N' && temp != 'n');

    //input lung illness
    do {
        cout << "Lung Ilness: ";
        cin >> temp;

        if (temp == 'y' || temp == 'Y')
            generalAnamnesis[3][patient] = true;
        else if (temp == 'n' || temp == 'N')
            generalAnamnesis[3][patient] = false;
    } while (temp != 'y' && temp != 'Y' && temp != 'N' && temp != 'n');

    //input hormones ilness
    do {
        cout << "Hormones Ilness: ";
        cin >> temp;

        if (temp == 'y' || temp == 'Y')
            generalAnamnesis[4][patient] = true;
        else if (temp == 'n' || temp == 'N')
            generalAnamnesis[4][patient] = false;
    } while (temp != 'y' && temp != 'Y' && temp != 'N' && temp != 'n');

    //input diabetes
    do {
        cout << "Diabetes: ";
        cin >> temp;

        if (temp == 'y' || temp == 'Y')
            generalAnamnesis[5][patient] = true;
        else if (temp == 'n' || temp == 'N')
            generalAnamnesis[5][patient] = false;
    } while (temp != 'y' && temp != 'Y' && temp != 'N' && temp != 'n');

    //input hereditary
    do {
        cout << "Hereditary Ilness: ";
        cin >> temp;

        if (temp == 'y' || temp == 'Y')
            generalAnamnesis[6][patient] = true;
        else if (temp == 'n' || temp == 'N')
            generalAnamnesis[6][patient] = false;
    } while (temp != 'y' && temp != 'Y' && temp != 'N' && temp != 'n');


}

// function to input extra oral examination
void inpextraoralexamination(bool generalAnamnesis[][NoP], int patient) {
    char temp = ' ';

    cout << "Enter patient Extra Oral Examination." << endl;
    cout << "Y for yes, N for no." << endl;

    //input symmetry
    do {
        cout << "Symmetry: ";
        cin >> temp;

        if (temp == 'y' || temp == 'Y')
            generalAnamnesis[7][patient] = true;
        else if (temp == 'n' || temp == 'N')
            generalAnamnesis[7][patient] = false;
    } while (temp != 'y' && temp != 'Y' && temp != 'N' && temp != 'n');

    //input ATM
    do {
        cout << "ATM (Temporomandibular Articulation): ";
        cin >> temp;

        if (temp == 'y' || temp == 'Y')
            generalAnamnesis[8][patient] = true;
        else if (temp == 'n' || temp == 'N')
            generalAnamnesis[8][patient] = false;
    } while (temp != 'y' && temp != 'Y' && temp != 'N' && temp != 'n');

    //input Pain
    do {
        cout << "Pain : ";
        cin >> temp;

        if (temp == 'y' || temp == 'Y')
            generalAnamnesis[9][patient] = true;
        else if (temp == 'n' || temp == 'N')
            generalAnamnesis[9][patient] = false;
    } while (temp != 'y' && temp != 'Y' && temp != 'N' && temp != 'n');

}


// function to modify patient details
void modifyPatientDetails(int id) {
    cout << "Modifying details for patient ID#" << iD[id - 1000] + 1000 << endl;

    int choice;
    do {
        cout << "Select the information to modify:" << endl;
        cout << endl;
        cout << "1. First Name" << endl;
        cout << "2. Father's Name" << endl;
        cout << "3. Last Name" << endl;
        cout << "4. Gender" << endl;
        cout << "5. Date of Birth" << endl;
        cout << "6. Phone Number" << endl;
        cout << "7. Address" << endl;
        cout << "8. Medical Record" << endl;
        cout << endl;
        cout << "9. Save Changes & Exit" << endl;
        cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            cout << "Enter the modified First name: ";
            cin >> firstName[id - 1000];
            break;
        case 2:
            cout << "Enter the modified Father's name: ";
            cin >> fatherName[id - 1000];
            break;
        case 3:
            cout << "Enter the modified Last name: ";
            cin >> lastName[id - 1000];
            break;
        case 4:
            char temp;
            cout << "Enter the modified Gender (M/F): ";
            cin >> temp;
            
            /*
            cin >> temp;
            sexe[id - 1000] = (temp == 'M' || temp == 'm');
            */
            while (temp != 'M' && temp != 'm' && temp != 'F' && temp != 'f') {
                cout << "Invalid Letter" << endl;
                cout << "Enter the modified Gender (M/F): ";
                cin >> temp;
            }


            if (temp == 'M' || temp == 'm')
                sexe[patient] = true;   // True for Male 
            else if (temp == 'F' || temp == 'f')
                sexe[patient] = false; // fasle for female 
            break;

        case 5:
            cout << "Enter the modified Date of birth (DD/MM/YYYY): ";
            cin >> birthDay[id - 1000];
            cin.ignore();
            cin >> birthMonth[id - 1000];
            cin.ignore();
            cin >> birthYear[id - 1000];
            GetpatientAge(birthDay, birthMonth, birthYear, age, iD[id - 1000]);
            break;
        case 6:
            cout << "Enter the modified Phone Number: ";
            cin.ignore();
            cin >> phoneNumber[id - 1000];
            break;
        case 7:
            cout << "Enter the modified Address: ";
            cin.ignore();
            cin.getline(address[id - 1000], 500);
            break;
        case 8:

            inpgeneralAnamnesis(generalAnamnesis, id - 1000);
            inpextraoralexamination(generalAnamnesis, id - 1000);
            InpsoftTissue(softTissue, id - 1000);

            cout << "Enter Teeth Problems: ";
            cin.ignore();
            cin.getline(teeth[id - 1000], 80);

            InpArticulation(articulation, id - 1000);
            InpExtraction(extraction, id - 1000);
            InpLocalIlness(localIlness, id - 1000);
            break;
        case 9:
            cout << "Exiting modification menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
            break;
        }

        cout << endl;

    } while (choice != 9);

    cout << "Patient details modified successfully!" << endl;
    cout << endl;
}



int main() {
   

    int menu = 0;
    int choice = 0;

    do { 
        displayWelcomeMessage();

        cout << "1. Enter a New Patient." << endl;
        cout << "2. Update Patient File." << endl;
        cout << "3. Display All Patients." << endl;
        cout << "4. Search Patient" << endl;
        cout << "5. Exit" << endl;
        cin >> menu;
        system("cls");

        if (menu == 1) {
            idPlacer(iD, patient);
            InpfirstName(firstName, patient);
            system("cls");
            InpfatherName(fatherName, patient);
            system("cls");
            InplastName(lastName, patient);
            system("cls");
            InpbirthdayDate(birthDay, birthMonth, birthYear, patient);
            system("cls");
            Inpaddress(address, patient);
            system("cls");
            GetpatientAge(birthDay, birthMonth, birthYear, age, patient);
            Inpsexe(sexe, patient);
            system("cls");
            InpphoneNumber(phoneNumber, patient);
            system("cls");
            inpgeneralAnamnesis(generalAnamnesis, patient);
            system("cls");
            inpextraoralexamination(generalAnamnesis, patient);
            system("cls");
            InpintraOralexamination();
            system("cls");

            patient++;
        }
        else if (menu == 2) {
            cout << "Enter a patient Id to modify: ";
            cin >> choice;
            modifyPatientDetails(choice);
            system("pause");
            system("cls");

        }
        else if (menu == 3) {

            listPatients(patient);
            system("pause");
            system("cls");

        }
        else if (menu == 4) {

            cout << "Enter The patient's Id: ";
            cin >> choice;

            cout << endl;

            if (choice >= 1000 && choice < patient + 1000) {
                printPatientDetails(choice);
            }
            else {
                cout << "Invalid patient ID!" << endl;
            }
            cout << endl;

            system("pause");
            system("cls");

        }

    } while (menu != 5);


    return 0;
}