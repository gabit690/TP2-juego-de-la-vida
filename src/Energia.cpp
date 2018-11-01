#include "Energia.h"

		Energia::Energia(float factorNacimientoParcela, float factorMuerteParcela){
			this->energiaTotal = 0;
			this->factorNacimiento = factorNacimientoParcela;
			this->factorMuerte = factorMuerteParcela;
		}

		float Energia::nacimientoCelular(){
			return (ENERGIA*(this->factorNacimiento));
		}

		float Energia::muerteCelular(){
			return (ENERGIA*(this->factorMuerte));
		}

		void Energia::sumarEnergia(){
			(this->energiaTotal) += nacimientoCelular();
		}

		void Energia::restarEnergia(){
			if(this->energiaTotal == muerteCelular()){
				this->energiaTotal = SIN_ENERGIA;
			}
			else{
				(this->energiaTotal) -= muerteCelular();
			}
		}
