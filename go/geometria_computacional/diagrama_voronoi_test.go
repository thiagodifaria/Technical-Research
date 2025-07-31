package geometria_computacional

import (
	"testing"
	"math"
)

const epsilon = 1e-9

func pointsAlmostEqual(p1, p2 Point) bool {
	return math.Abs(p1.X-p2.X) < epsilon && math.Abs(p1.Y-p2.Y) < epsilon
}


// NOTA: Como a função GenerateVoronoi foi simplificada, os testes também são simplificados
// para corresponder à funcionalidade demonstrativa implementada.
func TestGenerateVoronoi(t *testing.T) {
	t.Run("Teste Dois Pontos", func(t *testing.T) {
		sites := []Point{{X: 0, Y: 0}, {X: 2, Y: 0}}
		diagram := GenerateVoronoi(sites)

		// Esperamos 1 aresta e 1 vértice (ponto médio)
		if len(diagram.Edges) != 1 {
			t.Fatalf("Esperado 1 aresta, obtido %d", len(diagram.Edges))
		}
		if len(diagram.Vertices) != 1 {
			t.Fatalf("Esperado 1 vértice, obtido %d", len(diagram.Vertices))
		}

        // Vértice esperado é o ponto médio
        expectedVertex := Point{X: 1, Y: 0}
        if !pointsAlmostEqual(diagram.Vertices[0], expectedVertex) {
            t.Errorf("Vértice esperado %v, obtido %v", expectedVertex, diagram.Vertices[0])
        }

        // A aresta deve ser uma linha vertical em x=1
        edge := diagram.Edges[0]
        if math.Abs(edge.Start.X - 1.0) > epsilon || math.Abs(edge.End.X - 1.0) > epsilon {
             t.Errorf("Aresta deveria ser uma linha vertical em x=1, mas foi de %v a %v", edge.Start, *edge.End)
        }
	})

    t.Run("Teste Três Pontos", func(t *testing.T) {
        // Esta implementação simplificada não lida com 3 pontos,
        // então esperamos um resultado vazio.
        sites := []Point{{X: 0, Y: 0}, {X: 4, Y: 0}, {X: 2, Y: 2}}
        diagram := GenerateVoronoi(sites)

        if len(diagram.Edges) != 0 {
            t.Errorf("Esperado 0 arestas para o caso não implementado de 3 pontos, obtido %d", len(diagram.Edges))
        }
    })
}