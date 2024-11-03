import  java.util.*;


class Solution {
public boolean canFinish(int numCourses, int[][] prerequisites)  {

        List<List<Integer>> graph = new ArrayList<>();
        int i , tmp ;
        int size = prerequisites.length;

        for(i = 0; i < numCourses ; i++)
        {
            graph.add(new ArrayList<>());
        }

        int[] counter = new int[numCourses];
        Queue<Integer> q = new LinkedList<Integer>();

        //checking which course does not have any prerequisite
        for( i = 0 ;i < size ; i++)
        {
            counter[prerequisites[i][0]]++;

        }

        for( i = 0 ;i < numCourses ; i++)
        {

            if(counter[i] == 0)
            {
                q.add(i);
            }
            
        }

        int num = q.size();

        while(!q.isEmpty())
        {
            tmp = q.remove();

            for( i = 0; i < size ; i++)
            {
                if(prerequisites[i][1] == tmp)
                {
                    counter[prerequisites[i][0]]--;
                    if(counter[prerequisites[i][0]] == 0)
                    {
                        num++;
                        q.add(prerequisites[i][0]);
                    }                    
                }
            }
        }
        
        return num == numCourses;
        
    }
};