<?php
    
    //
    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("qsearch.php", ["title" => "Symbol search"]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST"){
        
        if(empty($_POST["symbol"])){
            redirect("quote.php");
        }
        else{
            $stock = lookup($_POST["symbol"]);
            if(!(empty($stock))){
                
                render("quote_view.php", ["symbol" => $stock["symbol"], "name" => $stock["name"] , "price" => $stock["price"]] );
            }
            else{
                apologize("This company does not exists!", "quote.php");
            }
        }
        
        
        
    }
    
    























?>