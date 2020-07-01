#include <iostream>
#include <vector>
#include "lib.h"
using namespace std;

string getGenre (Genre genre) {
    switch (genre) {
        case Comedy : {
            return "Comedy";
        }
        case Thriller : {
            return "Thriller";
        }
        case Western : {
            return "Western";
        }
        case Drama : {
            return "Dramar";
        }
        case Documentary : {
            return "Documentary";
        }
        case Fantasy : {
            return "Fantasy";
        }
    }
}

string getDirector (CDirector director) {
    switch (director) {
        case Spielberg : {
            return "Spielberg";
        }
        case Scorsese : {
            return "Scorsese";
        }
        case Hitchcock : {
            return "Hitchcock";
        }
        case Kubrick : {
            return "Kubrick";
        }
        case Tarkovsky : {
            return "Tarkovsky";
        }
        case Tarantino : {
            return "Tarantino";
        }
        case Nolan : {
            return "Nolan";
        }
    }
}

string Operator::Parts() {
    return ", Operator";
}
unsigned int Operator::Cost() {
    return 10000;
}

string Actor::Parts() {
    return ", Actor";
}
unsigned int Actor::Cost() {
    return 5000;
}

string Director::Parts() {
    return ", Director";
}
unsigned int Director::Cost() {
    return 120000;
}

string ScreenWriter::Parts()  {
    return ", ScreenWriter";
}
unsigned int ScreenWriter::Cost() {
    return 6000;
}

string Editor::Parts() {
    return ", Editor";
}
unsigned int Editor::Cost() {
    return 3500;
}

string SoundDirector::Parts() {
    return ", SoundDirector";
}
unsigned int SoundDirector::Cost() {
    return 7700;
}

string Producer::Parts() {
    return ", Producer";
}
unsigned int Producer::Cost() {
    return 8800;
}

Studio::Studio(Operator &operator1, Actor &actor1, Director &director1, ScreenWriter &screenwriter1, Editor &editor1,
               SoundDirector &sounddirectors1, Producer &producer1, unsigned int budget, unsigned int income) {
        this->operators = operator1;
        this->actors = actor1;
        this->directors = director1;
        this->screenwriters = screenwriter1;
        this->editors = editor1;
        this->sounddirectors = sounddirectors1;
        this->producers = producer1;
        this->budget = budget;
        this->income = income;

}

void Studio::increaseBudget() {
    cout << "Project's budget now is " << budget << "$" << endl;
}

void Studio::increaseIncome() {
    income += budget*2;
    cout << "Project's income now is " << income  << "$" << endl;
}

void Builder::addDirector()  {
    budget += directors.Cost();
    cout << directors.Parts();
}

void Builder::addScreenwriter() {
    budget += screenwriters.Cost();
    cout << screenwriters.Parts();
}

void Builder::addOperator() {
    budget += operators.Cost();
    cout << operators.Parts();
}

void Builder::addSoundDirector() {
    budget += sounddirectors.Cost();
    cout << sounddirectors.Parts();
}

void Builder::addActor() {
    budget += actors.Cost();
    cout << actors.Parts();
}

void Builder::addEditor() {
    budget += editors.Cost();
    cout << editors.Parts();
}

void Builder::addProducer() {
    budget += producers.Cost();
    cout << producers.Parts();
}

Studio* Builder::build() {
    return new Studio( operators, actors, directors, screenwriters, editors, sounddirectors, producers,
            budget,  income);
}

void StudioAmateurMovie::addOperator() {
    studio->budget += studio->operators.Cost();
    cout << "Amateur movie: " <<  studio->operators.Parts();
}

void StudioAmateurMovie::addActor() {
    studio->budget += studio->actors.Cost();
    cout << "Amateur movie: " << studio->actors.Parts();
}

void StudioArtMovie::addDirector() {
    studio->budget += studio->directors.Cost();
    cout << "Art movie: " << studio->directors.Parts();
}

void StudioArtMovie::addScreenwriter() {
    studio->budget += studio->screenwriters.Cost();
    cout << "Art movie: " <<  studio->screenwriters.Parts();
}

void StudioArtMovie::addOperator() {
    studio->budget += studio->operators.Cost();
    cout << "Art movie: " <<  studio->operators.Parts();
}

void StudioArtMovie::addActor() {
    studio->budget += studio->actors.Cost();
    cout << "Art movie: " << studio->actors.Parts();
}

void StudioProfessionalMovie::addActor() {
    studio->budget += studio->actors.Cost();
    cout << "Amateur movie: " << studio->actors.Parts();
}

void StudioProfessionalMovie::addDirector() {
    studio->budget += studio->directors.Cost();
    cout << "Art movie: " << studio->directors.Parts();
}

void StudioProfessionalMovie::addScreenwriter() {
    studio->budget += studio->screenwriters.Cost();
    cout << "Art movie: " <<  studio->screenwriters.Parts();
}

void StudioProfessionalMovie::addSoundDirector() {
    studio->budget += studio->directors.Cost();
    cout << "Professional movie" <<  studio->directors.Parts();
}

void StudioProfessionalMovie::addEditor() {
    studio->budget += studio->editors.Cost();
    cout << "Professional movie" << studio->editors.Parts();
}

void StudioProfessionalMovie::addOperator() {
    studio->budget += studio->operators.Cost();
    cout << "Art movie: " <<  studio->operators.Parts();
}

void Manual::setBuilder(Builder *newBuilder) {
    this->builder = newBuilder;
}

Studio* Manual::getStudio(Builder &builder) {
    Studio *studio;
    builder.addOperator();
    builder.addActor();
    builder.addDirector();
    builder.addScreenwriter();
    builder.addEditor();
    builder.addSoundDirector();
    builder.addProducer();
}

Movie::Movie(string name, Genre genre, unsigned int year, CDirector director) {
    this->name = name;
    this->genre = genre;
    this->year = year;
    this->director = director;
}

MovieCollection::MovieCollection() = default;

void MovieCollection::addNew(Movie movie)  {
    list.push_back(movie);
};

void MovieCollection::showAll()  {
    for (auto & i : list) {
        cout <<  i.name  << " , " << getGenre(i.genre) << " , " << i.year << " , " << getDirector(i.director) << endl;
    }
};