<%@ page language="java" %>
<!DOCTYPE html>
	<head> <title>Factorial of number</title></head>
	<body>
		<form name="fm" method="POST" action="factorial.jsp">
			Enter a number:<input type="text" name="number"/>
			<input type="submit" value="Get factorial of number">

		</form>
	<%

		if(request.getMethod().equals("POST"))
		{
			number=Integer.parseInt(request.getParameter("number"));

			int fact=1;

			for(int i=2;i<=number;i++)
			{
				fact=fact*i;
			}

			out.println("<h2> Factorial of "+number+" is "+fact"</h2>");
		}
	%>
	
	</body>
</html>
