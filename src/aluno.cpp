#include "aluno.h"

Aluno::Aluno(){
	nome = " ";
	matricula = " ";
	nota = 0;
	faltas = 0;
}
Aluno::Aluno(std::string _matricula, std::string _nome){
	nome = _nome;
	matricula = _matricula;
}
std::string Aluno::getNome(){
	return nome;
}
std::string Aluno::getMatricula(){
	return matricula;
}
int Aluno::getFaltas(){
	return faltas;
}
double Aluno::getNota(){
	return nota;
}
void Aluno::setFaltas(int f){
	faltas = f;
}
void Aluno::setNota(double n){
	nota = n;
}
std::ostream& operator<< (std::ostream &o, Aluno const a){
	o<<"Nome: "<<a.nome<<std::endl<<"Matricula: "<< a.matricula<<std::endl<<"Nota: "<< a.nota<<std::endl<<"Faltas: "<< a.faltas<<std::endl;
	return o;
}
AlunoTurma::AlunoTurma(){
	discente = new Aluno;
	faltas = 0;
	nota = 0;
	discente->setNota(0);
	discente->setFaltas(0);
}
AlunoTurma::AlunoTurma(Aluno* _discente, int _faltas, double _nota){
	discente = _discente;
	faltas = _faltas;
	nota = _nota;
	discente->setNota(_nota);
	discente->setFaltas(_faltas);
}
Aluno* AlunoTurma::getDiscente(){
	return discente;
}




