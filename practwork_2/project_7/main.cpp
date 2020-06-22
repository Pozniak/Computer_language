#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Card {
    int nominal;
    int mast;
    Card() {};
    Card (int a, int b): nominal(a), mast(b) {};
    friend ostream& operator << (ostream& outputStream, Card c)
    {
        return outputStream << to_string(c.nominal) + " "
               + to_string(c.mast);
    }
};
bool Color (Card a, Card b)
{
    if ((a.mast == b.mast) || (a.mast == 0 && b.mast ==1)
        || (a.mast == 2 && b.mast == 3) || (b.mast == 1 &&
                                            a.mast == 0) || (b.mast == 3 && a.mast == 2))
        return true;
    else return false;
}
bool Nominal (Card a, Card b)
{
    if (a.nominal == b.nominal)
        return true;
    else return false;
}
bool Queen(Card a)
{
    return (a.nominal== 6 && a.mast == 3);
}
bool Ace(Card a)
{
    return (a.nominal == 8);
}
int main(int argc, char **argv)
{
    vector <Card> koloda;
    for (int j=0; j<4; j++) {
        for (int i=0; i<9; i++) {
            koloda.push_back(Card(i, j));
        }
    }
    for (int i=0; i<36; i++)
        cout << koloda[i] << endl;
    random_shuffle(koloda.begin(),koloda.end());
    for (int i=0; i<36; i++)
        cout << koloda[i] << endl;
    for (auto it = ++koloda.begin(); it < koloda.end();
         it++) {
        it = adjacent_find (--it, koloda.end(), Color);
        if (it != koloda.end())
            cout << "Карты одного цвета: " <<*(it) <<" и " <<*(it++)<<'\n';
        }
    for (auto it = ++koloda.begin(); it < koloda.end();
         it++) {
        it = adjacent_find (--it, koloda.end(), Nominal);
        if (it != koloda.end())
            cout << "Карты одного номинала: " << *(it)
                 <<" и " <<*(it++)<<'\n';
    }
    auto it = find_if (koloda.begin(), koloda.end(),
                       Queen);
    cout << "Пиковая дама " << distance(koloda.begin(),
            it) << "-я в колоде" <<endl;
    cout << "Тузы в колоде на ";
    it = koloda.begin()-1;
    for (int i = 0; i < 4; i++) {
        it = find_if(it+1, koloda.end(), Ace);
        cout<< distance(koloda.begin(), it) << " ";
    }
    cout << "позициях" << endl;
    return 0;
}