<!DOCTYPE html>
<html>
    <head>Movie Actor</head>
    <body>
        <form method="POST" action="movie.php">
          <input type="radio" name="selected" value="movie">Display Movies <br>
          Enter Actor Name : <input type="text" name="actorName"> <br>  
          <input type="radio" name="selected" value="year">Update Release Year <br>
          Enter Movie Name : <input type="text" name="movieName"> <br>
          Enter New Year : <input type="Int" name="newYear" maxlength="4"><br>
          <input type="submit">
        </form>
    </body>
</html>