//C++ code
//VARIAVEL DO TIPO INTEIRA
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

void loop() {
static bool prog = false;
static bool pass = false;
static bool finalizar = false;
static String opcao = "";
static int  senha = 123;
static String msg = "";
static String temp_S1_VD = "";
static String temp_S2_VD = "";
static String temp_S3_VD = "";
static String temp_S1_AM = 3;
static String temp_S2_AM = 3;
static String temp_S3_AM = 3;
static String temp_S1_VM = "";
static String temp_S2_VM = "";
static String temp_S3_VM = "";







  static unsigned long tempo_anterior = 0;
  static unsigned int segundos = 0;
  unsigned long tempo_atual = millis();

  if (tempo_atual - tempo_anterior > 1000) {
    tempo_anterior = tempo_atual;
    segundos++;
    Serial.println(segundos);

    if (Serial.available() > 0) {
      mensagem = Serial.readString();
      mensagem.trim();
      Serial.println(mensagem);
    if(!prog){
      msg = Serial.readString();
      if(msg == "prog"){
        Serial.println("Modo Prog");
        prog = true;
      }
    }
    if(prog){
      if(!pass){
        Serial.println("Digite a senha");
        String senha prog = Serial.readString();
        if(senha == senha_prog.toInt()){
          Serial.println("Senha OK");
          pass= true;
        }
      }
      if(pass){
        Serial.println("Qual semaforo deseja aumentar ou diminuir 5 segundos \n1 \n2 \n3")
        opcao = serial.readString();
        opcao.trim();

        if(opcao == "1"){
          Serial.println("Tempo atualizado ")
          int tempoNovo1 = serial.readString();
        }
      }
      
    }
    }

      
        if (mensagem == "caminhao") {
      modo  = true;
      Serial.println("Modo caminhão ativado");
    } else if (mensagem == "normal") {
      modo = false;
      Serial.println("Modo normal ativado");
    }
    }
  }
if (!caminhao) {
if (segundos >= 0 && segundos <= 27) {
  digitalWrite(S1_VD, 1);
  digitalWrite(S1_AM, 0);
  digitalWrite(S1_VM, 0);

  digitalWrite(S2_VD, 0);
  digitalWrite(S2_AM, 0);
  digitalWrite(S2_VM, 1);

  digitalWrite(S3_VD, 0);
  digitalWrite(S3_AM, 0);
  digitalWrite(S3_VM, 1);

} else if (segundos >= 27 && segundos <= 30) {
  digitalWrite(S1_VD, 0);
  digitalWrite(S1_AM, 1);
  digitalWrite(S1_VM, 0);

  digitalWrite(S2_VD, 0);
  digitalWrite(S2_AM, 0);
  digitalWrite(S2_VM, 1);

  digitalWrite(S3_VD, 0);
  digitalWrite(S3_AM, 0);
  digitalWrite(S3_VM, 1);

} else if (segundos >= 30 && segundos <= 47) {
  digitalWrite(S1_VD, 0);
  digitalWrite(S1_AM, 0);
  digitalWrite(S1_VM, 1);

  digitalWrite(S2_VD, 1);
  digitalWrite(S2_AM, 0);
  digitalWrite(S2_VM, 0);

  digitalWrite(S3_VD, 0);
  digitalWrite(S3_AM, 0);
  digitalWrite(S3_VM, 1);
} else if (segundos > 47 && segundos <= 50) {
  digitalWrite(S1_VD, 0);
  digitalWrite(S1_AM, 0);
  digitalWrite(S1_VM, 1);

  digitalWrite(S2_VD, 0);
  digitalWrite(S2_AM, 1);
  digitalWrite(S2_VM, 0);

  digitalWrite(S3_VD, 0);
  digitalWrite(S3_AM, 0);
  digitalWrite(S3_VM, 1);
} else if (segundos >= 50 && segundos <= 72) {
  digitalWrite(S1_VD, 0);
  digitalWrite(S1_AM, 0);
  digitalWrite(S1_VM, 1);

  digitalWrite(S2_VD, 0);
  digitalWrite(S2_AM, 0);
  digitalWrite(S2_VM, 1);

  digitalWrite(S3_VD, 1);
  digitalWrite(S3_AM, 0);
  digitalWrite(S3_VM, 0);
} else if (segundos >= 72 && segundos <= 75) {
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
if (segundos == 75) {
  if (modo){
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
  } 
  else if (segundos >= 32 && segundos <= 35) {
    digitalWrite(S1_VD, 0);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 1);
    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 1);
    digitalWrite(S2_VM, 0);
    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 1);
  }
  else if (segundos >= 35 && segundos <= 57) {
    digitalWrite(S1_VD, 1);
    digitalWrite(S1_AM, 0);
    digitalWrite(S1_VM, 0);
    digitalWrite(S2_VD, 0);
    digitalWrite(S2_AM, 0);
    digitalWrite(S2_VM, 1);
    digitalWrite(S3_VD, 0);
    digitalWrite(S3_AM, 0);
    digitalWrite(S3_VM, 1);
  }
  else if (segundos >= 57 && segundos <= 60) {
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
  else if (segundos >= 60 && segundos <= 82) {
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
  else if(segundos >= 82 && segundos <= 85) {
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
    if (modo){
    caminhao = true;
  
  }
  if (!modo) {
    caminhao = false;
  }
  }
}
}

