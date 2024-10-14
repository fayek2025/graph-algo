import java.util.List;
import java.util.ArrayList;

public class reverse {
    static class Graph{
        int vertices;
        List<List <Integer>> adj;

        Graph(int vertices)
        {
            this.vertices = vertices;
           adj = new ArrayList<>(vertices);

           //initializing the 2D array
           for(int i = 0 ; i < vertices ; i++)
           {
                adj.add(new ArrayList<>());
           }


        }


        void addEdge(int source , int dest)
        {
            adj.get(source).add(dest);
        }

        public Graph reverse(Graph graph)
        {
            Graph reverse = new Graph(vertices);
            for(int i = 0 ; i < vertices ; i++)
            {
                List<Integer> nodeList = graph.adj.get(i);
                int source = i;
                for(Integer j : graph.adj.get(i))
                {
                    reverse.addEdge(j, i);
                }
            }    

            return reverse;
        }


        void printGraph()
        {
            for(int i = 0 ;i < vertices ; i++)
            {
                System.out.print( i + " is connected to " + ":");
                System.out.println(adj.get(i));
            }
        }
    }




    public static void main(String[] args) {
        Graph graph = new Graph(5);
        graph.addEdge(0,1);
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.addEdge(2, 3);
        graph.addEdge(3, 4);
        graph.addEdge(4, 0);
        System.out.println("---------------Original Graph---------------------------");
        graph.printGraph();
        Graph reverseGraph = graph.reverse(graph);
        System.out.println("---------------Reverse Graph---------------------------");
        reverseGraph.printGraph();
    
        
    }
    
}
