void main() {
  String status = 'ANDAMENTO';

  switch(status){
    case 'ABERTO':
    print('O seu pedido está aberto!');
    break;
    case 'FECHADO':
    print('O seu pedido está fechado!');
    break;
    case 'PENDENTE':
    print('O seu pedido está pendente!');
    break;
    case 'ANDAMENTO':
    print('O seu pedido está em andamento!');
    break;
    case 'ENTREGA':
    print('O seu pedido já saiu para entrega!');
    break;

  }
}
