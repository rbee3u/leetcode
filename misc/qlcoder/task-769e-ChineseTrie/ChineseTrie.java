import java.util.Random;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class ChineseTrie
{
	public static void main(String[] args)
	{
		int a=0x4e00;
		int b=0x9fa5;
		Random r=new Random(10);
		List<String> arr=new ArrayList<String>(50000000);
		StringBuilder s=new StringBuilder(20);
		for(int i=0;i<50000000;i++)
		{
			if (i % 1000000 == 0)
			{
				System.out.println(i);
			}
			int j=(int)(r.nextInt(4))+2;
			s.setLength(j);
			for(int jj=0;jj<j;jj++)
			{
				s.setCharAt(jj, (char)(a+(int)(r.nextInt(b-a))));
			}
			arr.add(s.toString());
			// System.out.println(s);
		}
		System.out.println("input done!");
		Collections.sort(arr);
		System.out.println("sort done!");
		int ans=1; String prev="";
		for (int i=0; i<50000000; ++i) {
			ans += prefix(prev, arr.get(i));
			prev = arr.get(i);
		}
		System.out.println(ans);
	}
	public static int prefix(String sa, String sb)
	{
		int na=sa.length(), nb=sb.length(), i=0;
		for (; (i < na) && (i < nb); ++i)
		{
			if (sa.charAt(i) != sb.charAt(i))
			{
				break;
			}
		}
		return (nb - i);
	}
}
