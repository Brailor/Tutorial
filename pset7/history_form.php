

    <table class="table table-striped">

    <thead>
        <tr>
            <th>Transaction</th>
            <th>Date</th>
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price</th>
        </tr>
    </thead>
    <tbody>
        <?php foreach($tables as $table): ?>
            <tr>
                <td><?= $table["action"] ?></td>
                <td><?= $table["date"] ?></td>
                <td><?= $table["symbol"] ?></td>
                <td><?= $table["name"] ?></td>
                <td><?= $table["shares"] ?></td>
                <td><?= number_format((float)$table["price"] , 2, '.', ',')?>$</td>
            </tr>
        <?php endforeach ?>
     

    </tbody>

    </table>




    