#include <iostream>
#include <set>
using namespace std;

class Message{
public:
    const string &getValue() const;
    int getClassification() const;
    void setValue(const string &value);
    void setClassification(int classification);

private:
    string value;
    int classification = 0;
};

const string &Message::getValue() const {
    return value;
}
int Message::getClassification() const {
    return classification;
}
void Message::setValue(const string &value) {
    Message::value = value;
}
void Message::setClassification(int classification) {
    Message::classification = classification;
}

class Classifier {
public:
    static Message* classifyMessages(string *messages, int size);
};

Message *Classifier::classifyMessages(string *messages, int size) {
    int c_count(0);
    set<string> data;

    Message *obj;
    obj = new Message[size];

//    Array in Obj abfüllen
    for (int i = 0; i < size; ++i) {
        obj[i].setValue(messages[i]);
        data.insert(messages[i]);
    }

//    Ausgabe
/*

    for (int j = 0; j < size; ++j) {
        cout << obj[j].getValue() << endl;
    }
*/

//    Regeln überprüfen
    for (int k = 0; k < size; ++k) {
//        1. Ist Message kürzer als 12 Zeichen
        if (obj->getValue().size() < 12) {
            obj[k].setClassification(c_count++);
        }

    }


//        2.0 Message kommt mehrmals im Array vor
//        2.1 Überprüfen, ob es doppelte Elemente gibt
        if (messages->size() != data.size()) {
            c_count++;

//        2.2 Falls es doppelte Elemente gibt, dann herausfinden welches


            set<string>::iterator it;
            int a_count(0);
            int tmp_count(0);
            for (it = data.begin(); it != data.end(); it++) {
                tmp_count++;
                if (*it != obj->getValue()) {

                }
            }


    }






    cout << "c_count" << c_count << endl;

    set<string>::iterator it;
    for (it=data.begin(); it!=data.end(); it++) {
        cout << *it << endl;
    }

    return 0;


    return obj;
}

int main() {
    int size(2);
    string *arr = new string[size]{"hallo", "wie", "hallo"};

    Classifier obj1;
    obj1.classifyMessages(arr, size);

    return 0;
}
