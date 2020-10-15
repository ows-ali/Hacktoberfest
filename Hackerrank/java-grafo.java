// Este é um exemplo simples de implementação de grafo representado por lista
// de adjacências

import java.util.List;
import java.util.ArrayList;

public class Grafo {
    public class Vertice {
        String nome;
        List<Aresta> adj;

        Vertice(String nome) {
            this.nome = nome;
            this.adj = new ArrayList<Aresta>();
        }

        void addAdj(Aresta e) {
            adj.add(e);
        }
    }

    public class Aresta {
        Vertice origem;
        Vertice destino;

        Aresta(Vertice origem, Vertice destino) {
            this.origem = origem;
            this.destino = destino;
        }
    }

    List<Vertice> vertices;
    List<Aresta> arestas;

    public Grafo() {
        vertices = new ArrayList<Vertice>();
        arestas = new ArrayList<Aresta>();
    }

    Vertice addVertice(String nome) {
        Vertice v = new Vertice(nome);
        vertices.add(v);
        return v;
    }

    Aresta addAresta(Vertice origem, Vertice destino) {
        Aresta e = new Aresta(origem, destino);
        origem.addAdj(e);
        arestas.add(e);
        return e;
    }

    public String toString() {
        String r = "";
        for (Vertice u : vertices) {
            r += u.nome + " -> ";
            for (Aresta e : u.adj) {
                Vertice v = e.destino;
                r += v.nome + ", ";
            }
            r += "\n";
        }
        return r;
    }

    public static void main(String[] args) {
        Grafo g = new Grafo();
        Vertice s = g.addVertice("s");
        Vertice t = g.addVertice("t");
        Vertice y = g.addVertice("y");
        Aresta st = g.addAresta(s, t);
        Aresta sy = g.addAresta(s, y);
        Aresta ty = g.addAresta(t, y);
        Aresta yt = g.addAresta(y, t);
        System.out.println(g);
    }
}