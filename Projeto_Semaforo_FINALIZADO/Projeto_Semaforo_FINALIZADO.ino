// Sistema de Semáforo com Modo Caminhão e Programável

const int S1_VD = D13;
const int S1_AM = D12;
const int S1_VM = D11;
const int S2_VD = D10;
const int S2_AM = D9;
const int S2_VM = D8;
const int S3_VD = D4;
const int S3_AM = D3;
const int S3_VM = D2;

int tempoVerde_S1 = 27; 
int tempoVerde_S2 = 17; 
int tempoVerde_S3 = 22;  
const int tempoAmarelo_S1 = 3;  
const int tempoAmarelo_S2 = 3;
const int tempoAmarelo_S3 = 3;
int tempoTotal = tempoVerde_S1 + tempoAmarelo_S1 + tempoVerde_S2 + tempoAmarelo_S2 + tempoVerde_S3 + tempoAmarelo_S3;

bool tempCaminhao = false;
bool caminhao = false;
bool modo = false;
bool prog = false;
bool usuarios = false;
bool pass = false;

String mensagem = "";
String mensagemUsuario = "";
String mensagemU = "";
String escolha = "";
int senha = 123;

unsigned long tempo_anterior = 0;
unsigned int segundos = 0;

int etapaProg = 0;
int ruaEscolhida = 0;

void setup() {
  pinMode(S1_VD, OUTPUT);
  pinMode(S1_AM, OUTPUT);
  pinMode(S1_VM, OUTPUT);
  pinMode(S2_VD, OUTPUT);
  pinMode(S2_AM, OUTPUT);
  pinMode(S2_VM, OUTPUT);
  pinMode(S3_VD, OUTPUT);
  pinMode(S3_AM, OUTPUT);
  pinMode(S3_VM, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long tempo_atual = millis();

  if (tempo_atual - tempo_anterior > 1000) {
    tempo_anterior = tempo_atual;
    segundos++;
    Serial.println(segundos);
  }

  if (!caminhao) {
    // Modo normal
    if (segundos < tempoVerde_S1) {
      digitalWrite(S1_VD, 1); digitalWrite(S1_AM, 0); digitalWrite(S1_VM, 0);
      digitalWrite(S2_VM, 1); digitalWrite(S3_VM, 1);
      digitalWrite(S2_VD, 0); digitalWrite(S2_AM, 0);
      digitalWrite(S3_VD, 0); digitalWrite(S3_AM, 0);
    } else if (segundos < tempoVerde_S1 + tempoAmarelo_S1) {
      digitalWrite(S1_VM, 0);
      digitalWrite(S1_VD, 0); digitalWrite(S1_AM, 1);
      digitalWrite(S2_VM, 1); digitalWrite(S3_VM, 1);
    } else if (segundos < tempoVerde_S1 + tempoAmarelo_S1 + tempoVerde_S2) {
      digitalWrite(S2_VD, 1); digitalWrite(S2_AM, 0); digitalWrite(S2_VM, 0);
      digitalWrite(S1_VM, 1); digitalWrite(S3_VM, 1);
      digitalWrite(S1_VD, 0); digitalWrite(S1_AM, 0);
    } else if (segundos < tempoVerde_S1 + tempoAmarelo_S1 + tempoVerde_S2 + tempoAmarelo_S2) {
      digitalWrite(S2_VD, 0); digitalWrite(S2_AM, 1); digitalWrite(S2_VM, 0);
      digitalWrite(S1_VM, 1); digitalWrite(S3_VM, 1);
    } else if (segundos < tempoVerde_S1 + tempoAmarelo_S1 + tempoVerde_S2 + tempoAmarelo_S2 + tempoVerde_S3) {
      digitalWrite(S3_VD, 1); digitalWrite(S3_AM, 0); digitalWrite(S3_VM, 0);
      digitalWrite(S1_VM, 1); digitalWrite(S2_VM, 1);
      digitalWrite(S2_VD, 0); digitalWrite(S2_AM, 0);
    } else if (segundos < tempoTotal) {
      digitalWrite(S3_VD, 0); digitalWrite(S3_AM, 1); digitalWrite(S3_VM, 0);
      digitalWrite(S1_VM, 1); digitalWrite(S2_VM, 1);
    } else {
      segundos = 0;
      if (tempCaminhao){
        caminhao = true;
      }
    }
  } else {
    // Modo caminhão 
    if (segundos <= 32) {
      // Semáforo 2 verde (32s)
      digitalWrite(S2_VD, 1); digitalWrite(S2_AM, 0); digitalWrite(S2_VM, 0);
      digitalWrite(S1_VM, 1); digitalWrite(S3_VM, 1);
      digitalWrite(S1_VD, 0); digitalWrite(S1_AM, 0);
      digitalWrite(S3_VD, 0); digitalWrite(S3_AM, 0);
    } else if (segundos <= 35) {
      // Semáforo 2 amarelo (3s)
      digitalWrite(S2_VD, 0); digitalWrite(S2_AM, 1); digitalWrite(S2_VM, 0);
    } else if (segundos <= 57) {
      // Semáforo 1 verde (22s)
      digitalWrite(S1_VD, 1); digitalWrite(S1_AM, 0); digitalWrite(S1_VM, 0);
      digitalWrite(S2_VM, 1); digitalWrite(S3_VM, 1);
      digitalWrite(S2_VD, 0); digitalWrite(S2_AM, 0);
    } else if (segundos <= 60) {
      // Semáforo 1 amarelo (3s)
      digitalWrite(S1_VD, 0); digitalWrite(S1_AM, 1); digitalWrite(S1_VM, 0);
    } else if (segundos <= 82) {
      // Semáforo 3 verde (22s)
      digitalWrite(S3_VD, 1); digitalWrite(S3_AM, 0); digitalWrite(S3_VM, 0);
      digitalWrite(S1_VM, 1); digitalWrite(S2_VM, 1);
      digitalWrite(S1_VD, 0); digitalWrite(S1_AM, 0);
    } else if (segundos <= 85) {
      // Semáforo 3 amarelo (3s)
      digitalWrite(S3_VD, 0); digitalWrite(S3_AM, 1); digitalWrite(S3_VM, 0);
    } else {
      segundos = 0;
      caminhao = false;  // Retorna ao modo normal após o ciclo
    }
  }

  if (Serial.available() > 0) {
    mensagem = Serial.readString();
    mensagem.trim();

    if (!prog) {
      if (mensagem == "prog") {
        prog = true;
        etapaProg = 1;
        Serial.println("Modo programação ativado.");
        Serial.println("Digite o nome de usuário:");
      } else if (mensagem.equalsIgnoreCase("caminhao")) {
        tempCaminhao = true;  // Ativa imediatamente o modo caminhão
        
        Serial.println("Modo caminhão ativado");
      } else if (mensagem == "normal") {
        tempCaminhao = false;
        
        Serial.println("Modo normal ativado");
      }
    } else {
      if (etapaProg == 1) {
        if (mensagem == "PEDRO_SENAI" || mensagem == "LURYAN_SENAI" || mensagem == "VITÓRIA_SENAI" || mensagem == "ARTHUR_SENAI") {
          etapaProg = 2;
          Serial.println("Usuário válido. Agora digite a senha:");
        } else {
          Serial.println("Usuário inválido. Tente novamente:");
        }
      } else if (etapaProg == 2) {
        if (mensagem.toInt() == senha) {
          etapaProg = 3;
          Serial.println("Senha correta! Digite a rua a alterar (1, 2, 3) ou 'sair' para encerrar:");
        } else {
          Serial.println("Senha incorreta. Tente novamente:");
        }
      } else if (etapaProg == 3) {
        if (mensagem == "sair") {
          prog = false;
          etapaProg = 0;
          Serial.println("Saindo do modo programação.");
        } else {
          ruaEscolhida = mensagem.toInt();
          if (ruaEscolhida >= 1 && ruaEscolhida <= 3) {
            etapaProg = 4;
            Serial.print("Digite o novo tempo do verde para a Rua ");
            Serial.print(ruaEscolhida);
            Serial.println(":");
          } else {
            Serial.println("Rua inválida. Digite 1, 2 ou 3, ou 'sair' para encerrar:");
          }
        }
      } else if (etapaProg == 4) {
        int novoTempo = mensagem.toInt();
        if (novoTempo > 0 && novoTempo < 100) {
          if (ruaEscolhida == 1) tempoVerde_S1 = novoTempo;
          else if (ruaEscolhida == 2) tempoVerde_S2 = novoTempo;
          else if (ruaEscolhida == 3) tempoVerde_S3 = novoTempo;

          tempoTotal = tempoVerde_S1 + tempoAmarelo_S1 + tempoVerde_S2 + tempoAmarelo_S2 + tempoVerde_S3 + tempoAmarelo_S3;

          Serial.println("Tempo alterado com sucesso.");
        } else {
          Serial.println("Tempo inválido. Tente novamente com valor entre 1 e 99.");
        }

        etapaProg = 3;
        Serial.println("Digite outra rua (1, 2, 3) ou 'sair' para encerrar:");
      }
    }
  }
}