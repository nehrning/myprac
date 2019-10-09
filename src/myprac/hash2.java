package myprac;

import java.util.*;

public class hash2 {
    public boolean solution(String[] phone_book) {
        HashMap<String, Integer> hm = new HashMap<String, Integer>();
        boolean answer = true;
        for(String str : phone_book)
            for(int i = 0; i < str.length(); i++)
                hm.put(str.substring(0,i+1), hm.getOrDefault(str.substring(0,i+1), 0) + 1);
        for(String str : phone_book)
            if(hm.get(str) > 1){
                answer = false;
                break;
            }
        return answer;
    }
}