#include <iostream>
#include <vector>
using namespace std;

enum Genre {
    Comedy,
    Thriller,
    Western,
    Drama,
    Documentary,
    Fantasy
};

enum CDirector {
    Spielberg,
    Scorsese,
    Hitchcock,
    Kubrick,
    Tarkovsky,
    Tarantino,
    Nolan
};

string getGenre(Genre genre);

string getDirector (CDirector director);

class BaseMethod {
public:
    virtual string Parts() = 0;
    virtual unsigned int Cost() = 0;
};

class Operator : public BaseMethod {
public:
    string Parts() override;
    unsigned int Cost() override;
};

class Actor : public BaseMethod {
public:
    string Parts() override;
    unsigned int Cost() override;
};

class Director : public BaseMethod {
public:
    string Parts() override;
    unsigned int Cost() override;
};

class ScreenWriter : public BaseMethod {
public:
    string Parts() override;
    unsigned int Cost() override;
};

class Editor : public BaseMethod {
public:
    string Parts() override;
    unsigned int Cost() override;
};

class SoundDirector  : public  BaseMethod {
public:
    string Parts() override;
    unsigned int Cost() override;
};

class Producer : public BaseMethod {
public:
    string Parts() override;
    unsigned int Cost() override;
};

class Studio {
public:
    Operator operators;
    Actor actors;
    Director directors;
    ScreenWriter screenwriters;
    Editor editors;
    SoundDirector sounddirectors;
    Producer producers;
    unsigned int budget = 0;
    unsigned int income = 0;

    Studio (Operator &operator1, Actor &actor1, Director &director1, ScreenWriter &screenwriter1, Editor &editor1, SoundDirector &sounddirectors1, Producer &producer1,
            unsigned int budget, unsigned int income);

    void increaseBudget();

    void increaseIncome();
};

class Builder {
    Operator operators;
    Actor actors;
    Director directors;
    ScreenWriter screenwriters;
    Editor editors;
    SoundDirector sounddirectors;
    Producer producers;
    unsigned int budget = 0;
    unsigned int income = 0;
public:
    virtual void addDirector();

    virtual void addScreenwriter();

    virtual void addOperator();

    virtual void addSoundDirector();

    virtual void addActor();

    virtual void addEditor();

    virtual void addProducer();

    Studio *build();
};

class StudioAmateurMovie : public Builder {
private:
    Studio *studio;
public:
    void addOperator() override;
    void addActor() override;
};

class StudioArtMovie : public Builder {
private:
    Studio *studio;
public:
    void addDirector() override;

    void addScreenwriter() override;

    void addOperator() override;

    void addActor() override;
};

class StudioProfessionalMovie : public Builder {
private:
    Studio *studio;
public:
    void addDirector() override;

    void addScreenwriter() override;

    void addOperator() override;

    void addSoundDirector() override;

    void addActor() override;

    void addEditor() override;
};

class Manual {
    Builder *builder;
public:
    void setBuilder(Builder *newBuilder);
    Studio* getStudio(Builder &builder);
};

class Movie {
public:
    string name;
    Genre  genre;
    unsigned int year;
    CDirector  director;

    Movie (string name, Genre genre, unsigned int year, CDirector director);
};

class MovieCollection {
public:
    MovieCollection();

    vector <Movie> list;

    virtual void addNew (Movie movie);

    virtual void showAll();
};


