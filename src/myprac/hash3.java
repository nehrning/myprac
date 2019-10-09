package myprac;

import java.util.*;

class hash3 {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> hm = new HashMap<String, Integer>();

        for(String[] strSet : clothes)
            hm.put(strSet[1], hm.getOrDefault(strSet[1], 0) + 1);

        Collection<Integer> al = hm.values();

        Iterator<Integer> it = al.iterator();

        while(it.hasNext())
            answer*=(it.next()+1);

        return answer-1;
    }
}