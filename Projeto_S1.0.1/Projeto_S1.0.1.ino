//C++ code
//VARIAVEL DO TIPO INTEIRA const int S1_VD = D13;
const int S1_VD = D13;  
const int S1_AM = D12;
const int S1_VM = D11;
const int S2_VD = D10;
const int S2_AM = D9;
const int S2_VM = D8;
const int S3_VD = D4;
const int S3_AM = D3;
const int S3_VM = D2;
bool caminhao = false;
String mensagem = "";
bool modo = false;

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
int tempoVerde_S1 = 30;
int tempoVerde_S2 = 20;
int tempoVerde_S3 = 25;
const int tempoAmarelo = 3;
int tempoTotal = tempoVerde_S1 + tempoAmarelo + tempoVerde_S2 + tempoAmarelo + tempoVerde_S3;

void loop() {
  static bool prog = false;
  static bool pass = false;
  static bool finalizar = false;
  static String opcao = "";
  static String mensagemUsuario = "";
  static String mensagemFinalizar = "";
  static int senha = 123;
  static String msg = "";


  static unsigned long tempo_anterior = 0;
  static unsigned int segundos = 0;
  unsigned long tempo_atual = millis();

  if (tempo_atual - tempo_anterior > 1000) {
    tempo_anterior = tempo_atual;
    segundos++;
    Serial.println(segundos);
  }
  if (segundos < tempoVerde_S1) {

    digitalWrite(S1_VD, 1);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 0);

    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 1);

    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 1);
  } else if (segundos < tempoVerde_S1 + tempoAmarelo) {

    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 1);
    digitalWrite(S1_VM, 0);

    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 1);

    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 1);
  } else if (segundos < tempoVerde_S1 + tempoAmarelo + tempoVerde_S2) {
   
    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 1);

    digitalWrite(S2_VD, 1);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 0);

    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 1);
  } else if (segundos < tempoVerde_S1 + tempoAmarelo + tempoVerde_S2 + tempoAmarelo) {
    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 1);

    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 1);
    digitalWrite(S2_VM, 0);

    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 1);
  } else if (segundos < tempoVerde_S1 + tempoAmarelo + tempoVerde_S2 + tempoAmarelo + tempoVerde_S3) {
    
    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 1);

    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 1);

    digitalWrite(S3_VD, 1);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 0);
  } else if (segundos < tempoTotal) {
   
    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 1);

    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 1);

    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 1);
    digitalWrite(S3_VM, 0);
  } else {
    segundos = 0;
    if (finalizar) {
      tempoVerde_S1 = tempoVerde_S1.toInt();
      tempoVerde_S2 = tempoVerde_S2.toInt();
      tempoVerde_S3 = tempoVerde_S3.toInt();
      prog = false;
      pass = false;
      finalizar = false;
      menu = true;
      menu_inicio = true;
      menuRua1 = false;
      menuRua2 = false;
      menuRua3 = false;
      String msg = "";
      String tempVerde_S1 = "";
      String tempVerde_S2 = "";
      String tempVerde_S3 = "";
    }
  }
}
}
}
if (mensagem == "caminhao") {
  modo = true;
  Serial.println("Modo caminhão ativado");
} 
else if (mensagem == "normal") {
  modo = false;
  Serial.println("Modo normal ativado");
}
}
if (!caminhao) {
  if (segundos < tempoVerde_S1) {
    digitalWrite(S1_VD, 1);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 0);

    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 1);

    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 1);

  } else if (segundos < tempoVerde_S1 + tempoAmarelo) {
    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 1);
    digitalWrite(S1_VM, 0);

    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 1);

    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 1);

  } else if (segundos < tempoVerde_S1 + tempoAmarelo + tempoVerde_S2) {
    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 1);

    digitalWrite(S2_VD, 1);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 0);

    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 1);
  } else if (segundos < tempoVerde_S1 + tempoAmarelo + tempoVerde_S2 + tempoAmarelo) {
    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 1);

    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 1);
    digitalWrite(S2_VM, 0);

    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 1);
  } else if (segundos < tempoVerde_S1 + tempoAmarelo + tempoVerde_S2 + tempoAmarelo + tempoVerde_S3) {
    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 1);

    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 1);

    digitalWrite(S3_VD, 1);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 0);
  }
  if (segundos == 75) {
    if (modo) {
      caminhao = true;
    }
    if (!modo) {
      caminhao = false;
    }
  }
}
if (caminhao) {

  if (segundos > 0 && segundos <= 32) {
    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 1);
    digitalWrite(S2_VD, 1);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 0);
    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 1);
  } else if (segundos >= 32 && segundos <= 35) {
    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 1);
    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 1);
    digitalWrite(S2_VM, 0);
    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 1);
  } else if (segundos >= 35 && segundos <= 57) {
    digitalWrite(S1_VD, 1);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 0);
    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 1);
    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 1);
  } else if (segundos >= 57 && segundos <= 60) {
    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 1);
    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 1);
    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 1);
    digitalWrite(S3_VM, 0);
  } else if (segundos >= 60 && segundos <= 82) {
    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 1);
    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 1);
    digitalWrite(S3_VD, 1);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 0);
  } else if (segundos >= 82 && segundos <= 85) {
    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 1);
    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 1);
    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 1);
    digitalWrite(S3_VM, 0);
  }
  if (segundos > 57) {
    segundos = 0;
    if (modo) {
      caminhao = true;
    }
    if (!modo) {
      caminhao = false;
    }
  }
}

  if (Serial.available() > 0) {
    if (!prog) {
      Serial.println("Se deseja entrar em modo progamar, digite: prog");
      mensagem = Serial.readString();
      mensagem.trim();
      if (mensagem == "prog") {
        Serial.println("Modo prog");
        prog = true;
      }
    } else if (prog) {
      if (!usuarios) {
        Serial.println("Qual seu usuario?: ");
        mensagemU = Serial.readString();
        mensagemU.trim();
        if (mensagemUsuario == "PEDRO_SENAI" || mensagemUsuario == "LURYAN_SENAI" || mensagemUsuario == "VITÓRIA_SENAI" || mensagemUsuario == "ARTHUR_SENAI") {
          Serial.println("Usuário permitido!");
          usuarios = true;
          Serial.println("Digite a senha: ");
        }
      } else if (usuarios) {
        if (!pass) {
          String senha_prog = Serial.readString();
          senha_prog.trim();
          if (senha_prog.toInt() == senha) {
            Serial.println("Senha OK!");
            pass = true;
            Serial.println("Qual rua que deseja alterar?\n 1\n 2 \n 3");
          }
        } else if (pass) {
          if (menu) {
            escolha = Serial.readString();
            escolha.trim();
            int escolhaV = escolha.toInt(); 
            if (escolhaV == 1) {
              if (menuRua1) {
                Serial.println("Digite o tempo para mudar o LED verde da rua 1: ");
                menuRuaA = false;
              }
            }
          } else if (escolhaV == 2) {
            if (menuRua2) {
              Serial.println("Digite o tempo para mudar o LED verde da rua 2: ");
              menuRuaB = false;
          }
        }
        else if (escolhaV == 3) {
            if (menuRua3) {
              Serial.println("Digite o tempo para mudar o LED verde da rua 3: ");
              menuRuaB = false;
          }
        }
      }
