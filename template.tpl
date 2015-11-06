<?php // レイアウトテンプレート名をテンプレート中で指定する場合 ?>
<?php $context['_layout'] = 'layout.tpl' ?>
<?php // レイアウトで使用する変数をテンプレート中で指定する場合 ?>
<?php $context['title'] = 'レイアウトのサンプル'; ?>
<h1><?=h($h1)?></h1>
<table>
<?php foreach ($list as $i=>$item): ?>
  <tr bgcolor="<?=$i % 2 ? '#FFCCCC' : '#CCCCFF'?>">
    <td><?=$i?></td>
    <td><?=h($item)?></td>
  </tr>
<?php endforeach ?>
</table>