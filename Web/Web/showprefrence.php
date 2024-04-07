<html>
    <head>
        <style>
            body{
                font-size: <?php echo $_COOKIE['fontSize']; ?>;
                font-style: <?php echo $_COOKIE['fontStyle']; ?>;
                color: <?php echo $_COOKIE['fontColor']; ?>;
                background-color: <?php echo $_COOKIE['background']; ?>;
            }
        </style>
    </head>
    <body>
        <h1>Prefrences Should be visible now </h1><br>
            font-size: <?php echo $_COOKIE['fontSize']?>;<br>
            font-style: <?php echo $_COOKIE['fontStyle'] ?>;<br>
            color: <?php echo $_COOKIE['fontColor'] ?>;<br>
            background-color: <? echo $_COOKIE['background'] ?>;<br>
    </body>
</html>
