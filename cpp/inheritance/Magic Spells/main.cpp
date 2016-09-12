#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;

class Spell {
private:
    string scrollName;
public:

    Spell() : scrollName("") {
    }

    Spell(string name) : scrollName(name) {
    }

    virtual ~Spell() {
    }

    string revealScrollName() {
        return scrollName;
    }
};

class Fireball : public Spell {
private:
    int power;
public:

    Fireball(int power) : power(power) {
    }

    void revealFirepower() {
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite : public Spell {
private:
    int power;
public:

    Frostbite(int power) : power(power) {
    }

    void revealFrostpower() {
        cout << "Frostbite: " << power << endl;
    }
};

class Thunderstorm : public Spell {
private:
    int power;
public:

    Thunderstorm(int power) : power(power) {
    }

    void revealThunderpower() {
        cout << "Thunderstorm: " << power << endl;
    }
};

class Waterbolt : public Spell {
private:
    int power;
public:

    Waterbolt(int power) : power(power) {
    }

    void revealWaterpower() {
        cout << "Waterbolt: " << power << endl;
    }
};

class SpellJournal {
public:
    static string journal;

    static string read() {
        return journal;
    }
};
string SpellJournal::journal = "";
/*
int lcs(string str1, string str2) {
    int** LCSMatrix = new int*[str1.length() + 1];

    for (int i = 0; i < str1.length() + 1; i++)
        LCSMatrix[i] = new int[str2.length() + 1];

    for (int i = 0; i < str1.length(); i++)
        LCSMatrix[i][0] = 0;

    for (int i = 0; i < str2.length(); i++)
        LCSMatrix[0][i] = 0;
        
        for(int i = 1 ; i < str1.length()+1 ; i++)
        {
            for(int j = 1 ; j < str2.length()+1 ; j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    LCSMatrix[i][j] = LCSMatrix[i-1][j-1]+1; 
                }else{
                    LCSMatrix[i][j] = max(LCSMatrix[i-1][j],LCSMatrix[i][j-1]);
                }
            }
        }
        
        for(int i = 0 ; i  < str1.length()+1 ; i++)
        {
            for(int j = 0 ; j  < str2.length() +1; j++)
                cout << LCSMatrix[i][j] << " ";
            cout << endl;
        }

    return LCSMatrix[str1.length()][str2.length()];
}
*/
void counterspell(Spell *spell) {

    if (SpellJournal::journal.length() == 0) {
        Waterbolt* water = dynamic_cast<Waterbolt*> (spell);
        Fireball* fire = dynamic_cast<Fireball*> (spell);
        Thunderstorm* thunder = dynamic_cast<Thunderstorm*> (spell);
        Frostbite* frost = dynamic_cast<Frostbite*> (spell);

        if (fire != NULL) {
            fire->revealFirepower();
        } else if (thunder != NULL) {
            thunder->revealThunderpower();
        } else if (frost != NULL) {
            frost->revealFrostpower();
        } else if (water != NULL) {
            water->revealWaterpower();
        }
    } else {
        int** LCSMatrix = new int*[spell->revealScrollName().length() + 1];

    for (int i = 0; i < spell->revealScrollName().length() + 1; i++)
        LCSMatrix[i] = new int[SpellJournal::journal.length() + 1];

    for (int i = 0; i < spell->revealScrollName().length()+1; i++)
        LCSMatrix[i][0] = 0;

    for (int i = 0; i < SpellJournal::journal.length(); i++)
        LCSMatrix[0][i] = 0;
        
        for(int i = 1 ; i < spell->revealScrollName().length()+1 ; i++)
        {
            for(int j = 1 ; j < SpellJournal::journal.length()+1 ; j++)
            {
                if(spell->revealScrollName()[i-1] == SpellJournal::journal[j-1])
                {
                    LCSMatrix[i][j] = LCSMatrix[i-1][j-1]+1; 
                }else{
                    LCSMatrix[i][j] = max(LCSMatrix[i-1][j],LCSMatrix[i][j-1]);
                }
            }
        }
        cout << LCSMatrix[spell->revealScrollName().length()][SpellJournal::journal.length()] << endl;
        SpellJournal::journal="";
    }


}

class Wizard {
public:

    Spell *cast() {
        Spell *spell;
        string s;
        cin >> s;
        int power;
        cin >> power;
        if (s == "fire") {
            spell = new Fireball(power);
        } else if (s == "frost") {
            spell = new Frostbite(power);
        } else if (s == "water") {
            spell = new Waterbolt(power);
        } else if (s == "thunder") {
            spell = new Thunderstorm(power);
        }
        else {
            spell = new Spell(s);
            cin >> SpellJournal::journal;
        }
        return spell;
    }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while (T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}