package topological_sort;
import java.util.*;
import java.io.*;

public class topsortFile {

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
       try {
        File file = new File("input.txt");

        Scanner scanner = new Scanner(file);

        int vertices = scanner.nextInt();
        int edges = scanner.nextInt();

        List<List<Integer>> adj = new ArrayList<>(vertices);

        for(int i = 0 ; i < vertices ; i++)
        {
            adj.add(new ArrayList<>());
        }

        for(int i = 0 ; i < edges ; i++)
        {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            adj.get(u).add(v);
        }

        sort(vertices, adj);

        
       } catch (Exception e) {
            e.printStackTrace();
       }
    }
    
}
