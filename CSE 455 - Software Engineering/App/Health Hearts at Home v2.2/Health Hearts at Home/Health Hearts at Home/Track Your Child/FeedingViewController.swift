//
//  FeedingViewController.swift
//  Health Hearts at Home
//
//  Created by Luis Enrique Alvarez on 2/14/18.
//  Copyright © 2018 Luis Enrique Alvarez. All rights reserved.
//

import UIKit
import Charts

class FeedingViewController: UIViewController {


    @IBOutlet weak var warninglabel: UILabel!
    @IBOutlet weak var txtTextBox: UITextField!
    
    @IBOutlet weak var chtChart: LineChartView!
    var numbers : [Double] = []
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Do any additional setup after loading the view.
    }
    
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    @IBAction func btnbutton(_ sender: Any) {
        
        let input  = Double(txtTextBox.text!) //gets input from the textbox - expects input as double/int
        if input != nil
        {
            numbers.append(input!) //here we add the data to the array.
            updateGraph()
            txtTextBox.text = ""
            warninglabel.text = ""
            
        } else
        {
            warninglabel.text = "Enter Only values"
            txtTextBox.text = ""
        }
        
    }
    
    @IBAction func clear(_ sender: Any) {
        
        numbers.removeAll() //removes all data inputs
        
        updateGraph() //updates the graph
    }
    
    func updateGraph(){
        //this is the Array that will eventually be displayed on the graph.
        
        var lineChartEntry  = [ChartDataEntry]()
        
        //here is the for loop
        for i in 0..<numbers.count {
            
            let value = ChartDataEntry(x: Double(i), y: numbers[i]) // here we set the X and Y status in a data chart entry
            
            lineChartEntry.append(value) // here we add it to the data set
        }
        
        let line1 = LineChartDataSet(values: lineChartEntry, label: "Data") //Here we convert lineChartEntry to a LineChartDataSet
        
        line1.colors = [NSUIColor.blue] //Sets the colour to blue
        
        
        let data = LineChartData() //This is the object that will be added to the chart
        
        data.addDataSet(line1) //Adds the line to the dataSet
        
        
        chtChart.data = data //finally - it adds the chart data to the chart and causes an update
        
        chtChart.chartDescription?.text = "Feeding Chart" // Here we set the description for the graph
        
    }
    

}
