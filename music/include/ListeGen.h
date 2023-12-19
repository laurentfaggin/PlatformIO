#pragma once

template <class TypeElement>
class Liste{
public:
	Liste() {
		this->m_nombreDElements = 0;
		this->m_capacite = 1;
		this->m_liste = new TypeElement[this->m_capacite];
	}

	Liste(int p_capacite) :
		m_nombreDElements(0),
		m_capacite(p_capacite),
		m_liste(nullptr)
	{
		if (p_capacite > 0) {
			m_liste = new TypeElement[p_capacite];
		}
	};

	~Liste() {
		if (this->m_liste != nullptr) {
			delete[] this->m_liste;
			this->m_liste = nullptr;
		}
	};

	int nombreDElement()const {
		return this->m_nombreDElements;
	}

	void ajouterFin(const TypeElement& p_element) {
		agrandirCapaciteSiNessaire();
		this->m_liste[this->m_nombreDElements] = p_element;
		++ this->m_nombreDElements;
	}


	void ajouterDebut(const TypeElement& p_element) {
		agrandirCapaciteSiNessaire();
		for (int i = this->m_nombreDElements; i > 0; --i) {
			this->m_liste[i] = this->m_liste[i - 1];
		}
		this->m_liste[0] = p_element;

		++this->m_nombreDElements;
	}

	void supprimer(const int& p_index) {
		for (int i = p_index; i < this->m_nombreDElements - 1; i++) {
			this->m_liste[i] = this->m_liste[i + 1];
		}
		-- this->m_nombreDElements;
	};

	void supprimerFin() {
		--this->m_nombreDElements;
	};

	TypeElement obtenir(const int& p_index) const {
		return this->m_liste[p_index];
	};

	void definir(const int& p_index, const TypeElement& p_element) {
		this->m_liste[p_index] = p_element;
	};

	TypeElement* begin() const{
		return m_liste;
	};

	TypeElement* end() const{
		return m_liste + m_nombreDElements;
	};

private:
	int m_nombreDElements;
	int m_capacite;
	TypeElement* m_liste;

	void agrandirCapaciteSiNessaire() {
		if (this->m_nombreDElements == this->m_capacite) {
			TypeElement* nouvelleListe = new TypeElement[this->m_capacite * 2];
			for (int i = 0; i < this->m_nombreDElements; ++i) {
				nouvelleListe[i] = this->m_liste[i];
			}
			delete[] this->m_liste;
			this->m_liste = nouvelleListe;
			this->m_capacite *= 2;
		}
	}
};

