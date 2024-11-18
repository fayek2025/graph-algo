import java.util.*;

public class KrushkalsMST {


    //edge class 
    static class  Edge {
        int src , des ,  weight;
        public Edge(int src , int des , int weight)
        {
            this.src = src;
            this.des = des;
            this.weight = weight;
        }
    }

    //subset class
    static class Subset{
            int parent , rank;

            public Subset(int parent , int rank)
            {
                this.parent = parent;
                this.rank = rank;
            }
    }

    private static int findRoot(Subset[] subset , int i)
    {
        if(subset[i].parent == i)
        {
            return subset[i].parent ;
        }

        subset[i].parent = findRoot(subset, subset[i].parent);

        return subset[i].parent;
    }

    static void union(Subset[] subset , int x , int y )
    {
        int rootX = findRoot(subset, x);
        int rootY = findRoot(subset, y);

        if(subset[rootX].rank > subset[rootY].rank)
        {
            subset[rootY].parent = rootX;
        }
        else if(subset[rootX].rank < subset[rootY].rank)
        {
            subset[rootX].parent = rootY;
        }
        else
        {
            subset[rootY].parent = rootX;
            subset[rootX].rank++;
        }
    }
    

    static  void Krushkals(int v , List<Edge> Edges)
    {
        int j = 0;
        int noOfEdges = 0;
        Subset[] subset = new Subset[v];

        Edge result[] = new Edge[v];


        for (int i = 0; i <v; i++) {
            subset[i] = new Subset(i, 0);
        }
        while (noOfEdges < v-1)
        {
            Edge nexEdge = Edges.get(j);


            int x = findRoot(subset, nexEdge.src);
            int y = findRoot(subset, nexEdge.des);

            if(x!= y)
            {
                result[noOfEdges] = nexEdge;
                union(subset, x, y);
                noOfEdges++;
            }

            j++;
        }

        System.out.println( 
            "Following are the edges of the constructed MST:"); 
        int minCost = 0; 
        for (int i = 0; i < noOfEdges; i++) { 
            System.out.println(result[i].src + " -- "
                               + result[i].des + " == "
                               + result[i].weight); 
            minCost += result[i].weight; 
        } 
        System.out.println("Total cost of MST: " + minCost); 

    }



    public static void main(String[] args) 
    { 
        int V = 4; 
        List<Edge> graphEdges = new ArrayList<Edge>( 
            List.of(new Edge(0, 1, 10), new Edge(0, 2, 6), 
                    new Edge(0, 3, 5), new Edge(1, 3, 15), 
                    new Edge(2, 3, 4))); 
  
        // Sort the edges in non-decreasing order 
        // (increasing with repetition allowed) 
        graphEdges.sort(new Comparator<Edge>() { 
            @Override public int compare(Edge o1, Edge o2) 
            { 
                return o1.weight - o2.weight; 
            } 
        }); 
  
        Krushkals(V, graphEdges); 
    } 
}
