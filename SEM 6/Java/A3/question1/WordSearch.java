//FINAL

import java.io.*;
class ReadFile extends Thread
{
	String word,name;
	public ReadFile(String word,String name)
	{
		this.word=word;
		this.name=name;	
	}
	public void start()
	{
		String str;
		boolean done=false;
		try
		{
			BufferedReader br=new BufferedReader(new FileReader(name));
			while(((str=br.readLine())!=null)&& done==false)
			{
				if(str.indexOf(word)!=-1)
				{
					System.out.println("word found in file -"+name);
					done=true;
				}
				else
				{
					System.out.println("Word not found in file -"+name);
				}
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}

class WordSearch
{
	public static void main(String args[]) throws IOException
	{
		File f1=new File(args[1]);
		System.out.print("\nDirectory is "+args[1]+"\n");
		if(f1.isDirectory())
		{
			File[] l=f1.listFiles();
			ReadFile readThread[]=new ReadFile[l.length];
			int j=0;
			for(int i=0;i<l.length;i++)
			{
				if(l[i].isFile() && l[i].getName().endsWith("txt"))
				{
					readThread[j]=new ReadFile(args[0],args[1]+"/"+l[i].getName());
					readThread[j++].start();
				}
			}
		}
	}
}
