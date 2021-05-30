void setStyle() {
  gROOT->SetStyle("Plain");
  gStyle->SetPalette(57);
  gStyle->SetOptTitle(0);
}

void pandemic() {
  TGraphErrors *gS = new TGraphErrors("dati.txt", "%lg %lg %*lg %*lg 0");
  gS->SetTitle("Andamento della pandemia; durata (giorni); numero di persone");
  gS->SetMarkerStyle(kFullCircle);
  gS->SetMarkerColor(kBlue);
  gS->SetLineColor(kBlue);
  TCanvas *mycanvas = new TCanvas;
  gS->Draw("ACP");

  TGraphErrors *gI = new TGraphErrors("dati.txt", "%lg %*lg %lg %*lg 0");

  gI->SetMarkerStyle(kFullCircle);
  gI->SetMarkerColor(kRed);
  gI->SetLineColor(kRed);
  gI->Draw("CP");

  TGraphErrors *gR = new TGraphErrors("dati.txt", "%lg %*lg %*lg %lg 0");
  gR->SetMarkerStyle(kFullCircle);
  gR->SetMarkerColor(kGreen);
  gR->SetLineColor(kGreen);
  gR->Draw("CP");

  TLegend *leg = new TLegend(.4, .6, .5, .7);
  leg->SetFillColor(kWhite);
  leg->AddEntry(gS, "Suscettibili");
  leg->AddEntry(gI, "Infetti");
  leg->AddEntry(gR, "Rimossi");
  leg->Draw("Same");
}
