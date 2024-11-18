import java.util.*;


public class topsort {

    static void toplogical_sort(int v , List<List<Integer>> adj , boolean[] visited , Stack<Integer> stack)
    {

        visited[v] = true;

        for(int i : adj.get(v))
        {
            if(!visited[i])
            {
                toplogical_sort(i, adj, visited, stack);
            }
        }

        stack.push(v);
    }


    static void sort(int v , List<List<Integer>> adj)
    {
        Stack<Integer> stack = new Stack<>();
        boolean[] visited = new boolean[v];
        for(int i = 0 ; i < v ; i++)
        {
            if(!visited[i])
            {
                toplogical_sort(i, adj, visited, stack);
            }
            
        }
        System.out.println("Topological Sort of the graph");

        while (!stack.empty()) {
            System.out.print(stack.pop() + " ");

            
        }
    }

    public static void main (String[] args)
    {
        int V = 4;

        // Edges
        List<List<Integer> > edges = new ArrayList<>();
        edges.add(Arrays.asList(0, 1));
        edges.add(Arrays.asList(1, 2));
        edges.add(Arrays.asList(3, 1));
        edges.add(Arrays.asList(3, 2));

        // Graph represented as an adjacency list
        List<List<Integer> > adj = new ArrayList<>(V);
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        for (List<Integer> i : edges) {
            adj.get(i.get(0)).add(i.get(1));
        }

        sort(V , adj);
        System.out.println();
    }
    
}
