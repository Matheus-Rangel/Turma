#ifndef _ALUNO_H_
#define _ALUNO_H_

#include <string>
#include <ostream>
class Aluno {
private:
	std::string matricula;
	std::string nome;
	int faltas;
	double nota;
public:
	Aluno();
	Aluno(std::string _matricula, std::string _nome);
	std::string getNome();
	std::string getMatricula();
	int getFaltas();
	double getNota();
	void setFaltas(int f);
	void setNota(double n);
	friend std::ostream& operator<< (std::ostream &o, Aluno const a);
};

class AlunoTurma {
private:
	Aluno* discente;
	int faltas;
	double nota;
public:
	AlunoTurma();
	AlunoTurma(Aluno* _discente, int _faltas, double _nota);
	Aluno* getDiscente();
};

#endif