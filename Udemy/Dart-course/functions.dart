void main() {
  boasvindas();
  double resultadoSimulador = simulador(56.55, 47.80);
  print(resultadoSimulador);
  print(calcularArea(15.60));
}

void boasvindas() {
  String nome = 'Jennifer';
  print('Bem vinda ' + nome);
}

double simulador(double valor1, double valor2){
  double resultado = valor1 / valor2;
  return resultado;
}

double calcularArea(double raio) => 3.14 * raio * raio;
