for i in range(0, int(input())):
    alunos, numero = [int(x) for x in input().split()]
    submissoes = list(map(int, input().split()))
    print(submissoes.index(min(submissoes, key=lambda x: abs(x - numero)))+1)
