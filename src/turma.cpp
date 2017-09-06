#include <iostream>
#include "turma.h"
Turma::Turma() {

}

Turma::~Turma() {}

int Turma::addAluno(AlunoTurma _aluno) {
	if(buscaAlunoPorMatricula(_aluno.getDiscente()->getMatricula()))
		return -1;
	else{
		alunos.push_back(_aluno);
		return 0;
	}
}

Aluno* Turma::buscaAlunoPorNome (std::string _nome) {
	for(std::vector<AlunoTurma>::iterator it = alunos.begin(); it != alunos.end(); it++){
		if(it->getDiscente()->getNome() == _nome)
			return it->getDiscente();
	}
	return NULL;
}

Aluno* Turma::buscaAlunoPorMatricula (std::string _matricula) {
	for(std::vector<AlunoTurma>::iterator it = alunos.begin(); it != alunos.end(); it++){
		if(it->getDiscente()->getMatricula() == _matricula)
			return it->getDiscente();
	}
	return NULL;
}
int Turma::removeAlunoPorNome (std::string _nome) {
	for(std::vector<AlunoTurma>::iterator it = alunos.begin(); it != alunos.end(); it++){
		if(it->getDiscente()->getNome() == _nome){
			alunos.erase(it);
			return 0;
		}
	}
	/* Remove o aluno com o nome indicado.
	   Retorna 0 caso o aluno seja encontrado e removido com sucesso.
	   Retorna -1 em caso contrário.
	   Dica: Para remover um elemento do vetor, utilize o metodo erase().
	*/
	return -1;
}
int 
Turma::removeAlunoPorMatricula (std::string _matricula) {
	for(std::vector<AlunoTurma>::iterator it = alunos.begin(); it != alunos.end(); it++){
		if(it->getDiscente()->getMatricula() == _matricula){
			alunos.erase(it);
			return 0;
		}
	}
    /* Remove o aluno com a matricula indicada.
	   Retorna 0 caso o aluno seja encontrado e removido com sucesso.
	   Retorna -1 em caso contrário.
	   Dica: Para remover um elemento do vetor, utilize o metodo erase().
	*/
	return -1;
}

void Turma::listaAlunos() {
	double mediat = 0;
	std::cout<<std::endl<<"Exibindo informações completa da turma:"<<std::endl;
	std::cout<<"Quantidade de Alunos: "<< alunos.size()<<std::endl<<std::endl;
	for(std::vector<AlunoTurma>::iterator it = alunos.begin(); it != alunos.end(); it++){
		std::cout<<"\tAluno "<<it - alunos.begin() + 1<<""<<std::endl; 
		std::cout << *(it->getDiscente())<<std::endl;
		mediat += it->getDiscente()->getNota();
	}
	mediat /= alunos.size();
	std::cout<<"Nota Media da turma: "<< mediat<<std::endl<<std::endl<<std::endl;
	/* Lista os dados de todos os alunos da turma, incluindo o total de faltas e nota. Utilize a sobrecarga do operador de inserção para a impressão dos dados do aluno. Deve listar ainda a quantidade de alunos e a média das notas dos alunos nesta turma.
	*/
}