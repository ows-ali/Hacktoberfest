var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var lines = input.split('\n');

/**
 * Escreva a sua solução aqui
 * Code your solution here
 * Escriba su solución aquí
 */

var nomeVendedor = lines.shift();
var salarioFixo = parseFloat(lines.shift());
var totalVendasMes = parseFloat(lines.shift());

var total = salarioFixo + (totalVendasMes*0.15);

console.log('TOTAL = R$ '+total.toFixed(2));
