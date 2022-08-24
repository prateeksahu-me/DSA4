import java.io.*;
import java.util.*;



class WordLadder {

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
       HashSet<String> hs=new HashSet<>(wordList);
        if(!hs.contains(endWord))
        {
            return 0;
        }
        int steps=1;
        Queue<String> q=new LinkedList<>();
        q.add(beginWord);
        while(!q.isEmpty())
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                String curr=q.poll();
                char a[]=curr.toCharArray();
                for(int j=0;j<a.length;j++)
                {
                    char temp=a[j];
                    for(char c='a';c<='z';c++)
                    {
                        if(a[j]==c) continue;
                        a[j]=c;
                        String test=new String(a);
                        if(test.equals(endWord)) return steps+1;
                        if(hs.contains(test))
                        {
                            q.add(test);
                            hs.remove(test);
                        }
                    }
                    a[j]=temp;
                }
            }
            steps++;
        }
        return 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String beginWord = scanner.nextLine();
        String endWord = scanner.nextLine();

        int n = scanner.nextInt();
        List<String> wordList = new ArrayList<String>();

        for (int i = 0; i < n; ++i) {
            String word = scanner.next();
            wordList.add(word);
        }
        scanner.close();
        int result = new WordLadder().ladderLength(beginWord, endWord, wordList);
        System.out.println(result);
    }
}