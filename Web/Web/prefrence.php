<html>
    <head></head>
    <body>
        <form method="POST" action="saveprefrences.php">
            Font Style :
                <select name="font_style">
                    <option value="Arial">Arial</option>
                    <option value="Times New Roman">Times New Roman</option>
                    <option value="Vardana">Vardana</option>
                </select><br>
            Font Size :
                <select name="font_size">
                    <option value="small">Small</option>
                    <option value="medium">Medium </option>
                    <option value="large">Large</option>
                </select><br>
            Font Color :
                <input type="color" name="font_color"><br>
            Background :
                <input type="color" name="background"><br>
                <input type="submit">
        </form>
    </body>
</html>