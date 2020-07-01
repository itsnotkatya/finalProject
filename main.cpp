#include <iostream>
#include <vector>
#include "lib.h"
using namespace std;

int main() {

    Builder builder;
    builder.addActor();
    builder.addDirector();
    builder.addOperator();
    builder.addScreenwriter();
    cout << endl;

    Studio *studio = builder.build();
    studio->increaseBudget();
    studio->increaseIncome();

    Movie movie1("Time", Fantasy, 2014, Nolan);
    Movie movie2("Wide Eyes Shut", Drama, 1999, Kubrick);
    Movie movie3 ("Once upon in Hollywood", Western, 2019, Tarantino);
    Movie movie4 ("Stalker", Drama, 1986, Tarkovsky);
    Movie movie5 ("Psycho", Thriller, 1960, Hitchcock);
    MovieCollection Collection;
    Collection.addNew(movie1);
    Collection.addNew(movie2);
    Collection.addNew(movie3);
    Collection.addNew(movie4);
    Collection.addNew(movie5);
    Collection.showAll();

    return 0;
}