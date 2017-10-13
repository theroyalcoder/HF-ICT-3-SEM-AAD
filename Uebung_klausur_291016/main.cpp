#include <iostream>
using namespace std;

class Message{
public:
    const string &getValue() const;
    void setValue(const string &value);
    int getClassification() const;
    void setClassification(int classification);

private:
    string value;
    int classification = 0;
};

const string &Message::getValue() const {
    return value;
}
void Message::setValue(const string &value) {
    Message::value = value;
}
int Message::getClassification() const {
    return classification;
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

    for (int i = 0; i < messages->size(); ++i) {
        if (messages->size() < 12) {
            c_count++;
        }
    }

    return nullptr;
}

int main() {


    return 0;
}
