<?php

    // configuration
    require("../includes/config.php"); 
    
    $rows = CS50::query("SELECT symbol, shares FROM portfolio WHERE user_id = ?", $_SESSION["id"]);
    $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    
    $positions = [];
    
    foreach($rows as $row){
        
        $stock = lookup($row["symbol"]);
        if($stock != false){
            
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "symbol" => $row["symbol"],
                "shares" => $row["shares"]
                ];
        }
        
    }

    // render portfolio
    render("portfolio.php", ["positions" => $positions,"penz" => $cash[0]]);

?>
