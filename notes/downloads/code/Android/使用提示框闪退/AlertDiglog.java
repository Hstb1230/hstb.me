AlertDialog.Builder dialog = new AlertDialog.Builder(getApplicationContext()));
dialog.setIcon(R.mipmap.ic_launcher);
dialog.setTitle("System Waring");
dialog.setMessage("This is a warning");
dialog.setPositiveButtonIcon(getResources().getDrawable(R.drawable.reconnect));
dialog.setPositiveButton("continue", new DialogInterface.OnClickListener() {
    @Override
    public void onClick(DialogInterface dialogInterface, int i) {
        Toast.makeText(getApplicationContext(), "Click continue", Toast.LENGTH_SHORT).show();
    }
});
dialog.setNegativeButtonIcon(getResources().getDrawable(R.drawable.unlink));
dialog.setNegativeButton("cancel", new DialogInterface.OnClickListener() {
    @Override
    public void onClick(DialogInterface dialogInterface, int i) {
        Toast.makeText(getApplicationContext(), "Click cancel", Toast.LENGTH_SHORT).show();
    }
});
dialog.show();